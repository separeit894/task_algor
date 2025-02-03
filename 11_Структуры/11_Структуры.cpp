#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <string>


#define DEBUG 1


using namespace std;
using std::getline;


string path = "orders.txt";

struct ORDER {
	string payerAccount;       // Расчетный счет плательщика (5 знаков)
	string recipientAccount;   // Расчетный счет получателя (5 знаков)
	double amount;                  // Перечисляемая сумма в рублях
};


void Write_File_Data()
{
	
	ofstream file;
	file.open(path, ofstream::app);
	int count_payerAccount;
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		
		cout << "Файл открылся успешно!" << endl;
		
		/*cout << "Cкольких плательщиков вы хотите ввести? : ";
		cin >> count_payerAccount;*/
		int i = 0;
		string temp;
		cout << "Введите данные плательщика " << i << ": ";
		while(getline(cin, temp))
		{
			i++;
			//cout << "Введите данные плательщика " << i << ": ";
			 // Используем getline для ввода строки с пробелами
			cout << "Введите данные плательщика " << i << ": ";
			if (temp == "exit")
			{
				break;
			}
			file << temp << endl;
			
			
		}
		
		file.close();
	}
	

}



void Read_File_Data(vector<ORDER>& orders)
{
	
	fstream file;
	file.open(path, fstream::in);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл успешно открылся!" << endl;
			
		ORDER order;
		while (file >> order.payerAccount >> order.recipientAccount >> order.amount) {
			orders.push_back(order);
		}
		
	}

	file.close();
}


void PrintOrders(const vector<ORDER>& orders) {
	cout << "Список заказов (отсортировано):" << endl;
	for (vector<ORDER>::const_iterator it = orders.begin(); it != orders.end(); it++) {
		cout << "Плательщик: " << it->payerAccount
			<< ", Получатель: " << it->recipientAccount 
			<< ", Сумма: " << it->amount << " руб." << endl;
	}
}

void The_Amount_Withdrawn_From_The_Settlement_Center(const string& user, const vector<ORDER>& orders)
{
	bool found = false;
	
	for (vector<ORDER>::const_iterator it = orders.begin(); it != orders.end(); it++) 
	{

		if (user == it->payerAccount) 
		{
			cout << "Он нашел его: " << it->payerAccount << " - " << it->amount << " руб." << endl;
			found = true;
			break; 
		}
	}
		
	if (!found)
	{
		cout << "Расчетный счет не найден." << endl;
	}
	
}

// Функция для сортировки заказов по расчетным платежам
bool CompareByAmount(const ORDER& a, const ORDER& b) {
	return a.payerAccount < b.payerAccount; // Сортировка по возрастанию
}


int main()
{
	setlocale(LC_ALL, "Rus");
	vector<ORDER> order;

	#if DEBUG==0
	Write_File_Data();

	#endif 

	#if DEBUG==1
	Read_File_Data(order);
	sort(order.begin(), order.end(), CompareByAmount);

	PrintOrders(order);

	cout << "Введите расчетный счет плательщика: ";
	string user;
	cin >> user;
	The_Amount_Withdrawn_From_The_Settlement_Center(user, order);
	#endif
	
	return 0;
}ы