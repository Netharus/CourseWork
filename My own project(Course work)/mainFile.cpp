#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include<time.h>

using namespace std;
struct account
{
	string login;
	string password;
	int role;

};
struct Toys {
	string name;
	string price;
	string producer;
	int amount;
	int age_limit;
};

const string USERSINFORMATION = "Users.txt";
const string TOYSINFORMATION = "ToysRange.txt";
const string ERRORWITHFILES = "Error with file";
const string ADMIN = "ADMIN";
const string ENGINEER = "Engineer";
const string GUEST = "Guest";
const string MANAGER = "Manager";
const string CUSTOMER = "Customer";

bool num_limits(vector<int>arr, vector<account>arr_2);
void admin_menu(account& user, vector<account>& arr);
void vector_sort(vector<int>& arr);
void vector_prep_to_del(vector<int>& arr);
void show_role_menu();
void show_user_data_for_admin(vector<int>& pos, vector<account>& arr);
void guest_creation(account& user);
void account_info(account& user, vector<account>& arr);
void show_status(int role);
account account_entering(vector<account>& arr);
bool is_data_valid(vector<account>& arr, account& user);
account log_in(account& user, vector <account>& arr);
account account_creation(vector <account>& arr);
void core(vector <account>& arr);
bool compare(string& str1, string& str2);
bool check_empty();
bool check();
bool check_str(string& str);
void del_user(vector <account>& arr, int choice);
void show_data(vector <account>& arr);
int menu(int role);
void write_file(vector <account>& arr);
void read_file(vector <account>& arr);
int find_pos(vector<account>& arr, string login);
void data_change(account& user, int choice, vector<account>& arr, int position,int menu);
short validation_error();
bool login_compare(vector<account>& arr, string login);
string login_creation(string false_login);
void user_information_change(account& user, int choice, vector<account>& arr, int position,int menu);
short information_changing_menu(int role,int menu);
bool check_str_for_num(string str);
void user_position_data(string str, vector<int>& num_list);

int main() {
	vector <account> arr;
	int n = 0;
	

	read_file(arr);
	core(arr);
	write_file(arr);

	return 0;
}
void core(vector <account>& arr) {
	account user;
	bool flag = true;
	guest_creation(user);
	while (flag) {

		switch (menu(user.role)) {
		case 1: user=log_in(user,arr);
			break;
		case 2:;//del_user(arr,);
			break;
		case 3: admin_menu(user,arr);
			break;
		case 4: show_data(arr);
			break;
		case 5: user=account_creation(arr);
			break;
		case 6:account_info(user,arr);
			break;
		case 0:flag = false;
			break;
		default:;
			break;
		}
	}
}
void del_user(vector <account>& arr,int choice) {

	if (choice != 0) {
		arr.erase(arr.begin() + choice);
	}

}
void show_data(vector <account>& arr) {

	cout << "\t\t\t\t" << "User data:" << endl;
	for (int i = 0;i < arr.size();i++) {
		cout << i << ")" << "Log:" << arr[i].login << endl;
	}
	cout << "\n" << endl;
}
int menu(int role) {
	int choice;

	do {
		cout << "1--Log in\n2--delete user\n3--update user data\n4--show users\n5--Registration\n6--Profile\n0--exit" << endl;
		cin >> choice;
	} while (check());
	return choice;
}
bool check_str(string& str) {																							//Проверка строки на некоректный ввод, в данном случаи на ввод цифр
	int n = str.length();
	bool flag = false;
	for (int i = 0;i < n;i++) {
		if (str[i] == ' ') {
			flag = true;

		}
	}
	if (flag) {
		cout << "Error!! Only Symbols(English)" << endl;
	}
	return flag;
}
bool check() {																					//Проверка строки на некоректный ввод, в данном случаи нечисловой ввод
	if (cin.get() == '\n') {
		return false;
	}
	else {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "Error!! Only Numbers" << endl;
		return true;
	}
}
void write_file(vector <account>& arr) {
	ofstream fout;
	fout.open(USERSINFORMATION);
	if (!(fout.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else {
		for (int i = 0;i < arr.size();i++) {
			fout << arr[i].login << "\n" << arr[i].password << "\n" << arr[i].role;
			if (i != arr.size()) {
				fout << "\n";
			}
			else {

			}
		}
	}
	fout.close();
	arr.clear();
}
void read_file(vector <account>& arr) {
	ifstream fin;
	account stud;

	fin.open(USERSINFORMATION);
	if (!(fin.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else if (check_empty()) {
		stud.login = "admin";
		stud.password = "admin";
		stud.role = 0;
		arr.push_back(stud);
	}
	else {
		for (int i = 0;!(fin.eof());i++) {

			getline(fin, stud.login);
			getline(fin, stud.password);
			fin >> stud.role;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!(stud.login.empty())) {
				arr.push_back(stud);
			}
			else {
				break;
			}

		}
	}
	fin.close();
}
bool check_empty() {
	bool flag = false;
	string buff;
	ifstream fin;

	fin.open(USERSINFORMATION);

	getline(fin, buff);

	if (buff.empty()) {
		flag = true;
	}

	fin.close();

	return flag;
}
bool compare(string& str1, string& str2) {
	bool flag = true;
	if (str1.length() != str2.length()) {
		flag = false;
	}
	else {
		for (int i = 0;i < str1.length();i++) {
			if (str1[i] != str2[i]) {
				flag = false;
			}
		}
	}
	return flag;
}
account log_in(account& user, vector <account>& arr) {
	short choice;

	do {
		cout << "Do you have an account?\n1--Yes\t2--No" << endl;
		cin >> choice;
	} while (check() || (choice != 1 && choice != 2));
	switch (choice) {
	case 1:user = account_entering(arr);
		break;
	case 2:user = account_creation(arr);
		break;
	default:;
	}
	return user;
}
account account_creation(vector <account>& arr) {
	account user;
	system("cls");
	do {
		do {
			cout << "Log:";
			getline(cin, user.login);
			if (login_compare(arr, user.login)) {
				cout << "You can't use that nickname,try another one, for example that one -- "<<login_creation(user.login) << endl;
			}
			
		} while (login_compare(arr, user.login));
		cout << "Password:";
		cin >> user.password;
	} while (check_str(user.login));
	user.role = 2;
	arr.push_back(user);
	return user;
}
bool is_data_valid(vector<account>& arr, account& user) {
	for (int i = 0;i < arr.size();i++) {
		if (!compare(arr[i].login, user.login)) {
			if (i == ( arr.size()-1)) {
				return false; }
		}
		else {
			return compare(arr[i].password, user.password);
		}
	}
}
account account_entering(vector<account>& arr) {
	account user;
	while (1) {

		cout << "Log:";
		getline(cin, user.login);
		cout << "Password:";
		cin >> user.password;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (is_data_valid(arr, user)) {
			return arr[find_pos(arr, user.login)];
		}
		else {
			switch (validation_error()) {
			case 1:;
				break;
			case 2:return account_creation(arr);
				break;
			case 3:	user.login = "guest";
				user.password = 1;
				user.role = 1;
				return user;
				break;
			}
		}
	}	
}
void account_info(account& user, vector<account>& arr) {
	short choice;
	cout << "Profile information\nLogin:" << user.login << "\nPassword:" << user.password << endl;
	cout << "Status:";
	show_status(user.role);
	if (user.role!=1) {
		do {
			cout << "If you want to change data press 1, you want to leave that menu press 2" << endl;
			cin >> choice;
		} while (check() || (choice != 1 && choice != 2));
		if (choice == 1) {
			data_change(user, information_changing_menu(user.role,1), arr, find_pos(arr, user.login),1);
		}
		else {}
	}
	else {
	
		cout << "If you want to leave that menu press any bottom" << endl;

		_getch();

	}
}
void show_status(int role) {
	switch (role) {
	case 0:cout << ADMIN << endl;
		break;
	case 1:cout << GUEST << endl;;
		break;
	case 2:cout<<CUSTOMER<<endl;
		break;
	case 3:cout<<MANAGER<<endl;
		break;
	case 4:cout << ENGINEER << endl;
		break;
	}
}
int find_pos(vector<account>& arr, string login) {
	
	for (int i = 0;i < arr.size();i++) {
		if (compare(arr[i].login,login)) {
			return i;
		}
	}
	
}
void data_change(account &user,int choice,vector<account>&arr,int position,int menu) {
	user_information_change(user, choice,arr,position,menu);
	if (menu !=0) {
		user = arr[position];
	}
}
short validation_error() {
	short choice;
	do {
		cout << "Sorry we don't have that account,or you've created a mistake" << endl;
		cout << "What would you like to do\n 1--Try again?\t2--Create an account?\t3--Stay as guest?" << endl;
		choice = _getch();
	} while (check() || (choice < 1 && choice > 3));
	return choice;
}
void guest_creation(account&user) {
	user.login = "Guest";
	user.password = 1;
	user.role = 1;
}
bool login_compare(vector<account>&arr,string login) {
	for (int i = 0;i < arr.size();i++) {
		if (!compare(arr[i].login,login)) {
			if (i == (arr.size() - 1)) {
				return false;
			}
		}
		else {
			return true;
		}
	}
}
string login_creation(string false_login) {
	short amount,symbol_type;
	srand(time(NULL));
	amount = 1 + rand() % 7;
	for (int i = 0;i <= amount;i++) {
		symbol_type = 1+rand() % 2;
		switch (symbol_type) {
		case 1:false_login.push_back((char)(48 + rand() % 9));
			break;
		case 3:false_login.push_back((char)(65 + rand() % 25));
			break;
		case 2:false_login.push_back((char)(97 + rand() % 25));
			break;
		}
	}

	return false_login;
}
void user_information_change(account& user, int choice,vector<account>&arr,int position,int menu) {
	switch (choice) {
	case 1:cout << "Log:";
		getline(cin, arr[position].login);
		
		break;
	case 2:cout << "Password:";
		cin >> arr[position].password;;
		break;
	case 3:cout << "Log:";
		getline(cin, arr[position].login);
		cout << "Password:";
		cin >> arr[position].password;;
		break;
	case 4:del_user(arr, position);
		if (user.role != 0&&menu!=0) {
			
			guest_creation(user);
		}
		else {
			if (menu != 0) {
				cout << "You can't delete admin" << endl;
			}
		}
		break;
	case 5:show_role_menu();
		cout<<"Role:"<<endl;
		do
		{
			cin >> arr[position].role;

		} while (check() || (choice < 2 && choice > 4));
		cout << "Now "<<arr[position].login << " is ";
		show_status(arr[position].role);
		break;
	}
	if (menu != 0) {
		cout << "mission complited!" << endl;
	}
}
short information_changing_menu(int role,int menu) {
	short choice;

	if (menu==0) {
		cout << " What would you like to do with user/users \n1--Change Login\t2--Change Password\t3--Change login ,password\t4--Change role\t5--Delete" << endl;
		do {
			cin >> choice;
		} while (check() || (choice < 1 && choice > 5));
		if (choice == 4) {
			choice = 5;
		}else
		if (choice==5) {
			choice = 4;
		}
	}
	else {
		cout << "What would you like to change?\n1--Login\t2--Password\t3--Both\t4--Delete account" << endl;
		do {
			cin >> choice;
		} while (check() || (choice < 1 && choice > 4));
	}
	
	
	cout << endl;
	return choice;
}
void admin_menu(account& user,vector<account>&arr ) {
	int user_pos,choice, confirmation;
	string user_pos_string;
	vector<int>num_list;
	system("cls");
	choice=information_changing_menu(user.role, 0);
	do {
		num_list.clear();
		do {
			do {
				show_data(arr);
				cout << "Enter user or users position separated by commas" << endl;
				getline(cin, user_pos_string);
			} while (check_str_for_num(user_pos_string));
			user_position_data(user_pos_string, num_list);
			if (user_pos_string.empty()) {
				num_list.clear();
			}
		} while (num_limits(num_list,arr)||user_pos_string.empty());
		cout << "Are you shure that you'd like to change that user/users data?" << endl;
		show_user_data_for_admin(num_list, arr);
		cout << "1--yes\t2--no" << endl;
		cin >>confirmation;
	} while (check()||confirmation==2);
	vector_sort(num_list);
	if (choice==4) {
		vector_prep_to_del(num_list);
	}
	for (int i:num_list) {
		data_change(user, choice, arr,i,0);
	}
	num_list.clear();
	cout << "mission complited" << endl;
}
void show_role_menu() {
	cout<<"2--Customer\n3--Manager\n4--Programist" << endl;
}
void user_position_data(string str, vector<int>& num_list) {
	int num_len = 0, num = 0, buff;

	for (int i = 0;i <= str.size();i++) {
		if (str[i] != ',' && str[i] != ' ' && str[i] != '.' && str[i] != '\0') {
			num_len++;
		}
		else {
			for (int j = num_len;j > 0;j--) {
				buff = ((int)(str[i - j]) - 48) * pow(10, j - 1);
				num += buff;
			}
			num_list.push_back(num);
			num_len = 0;
			num = 0;
		}
	}
}
bool check_str_for_num(string str) {

	for (char& c : str) {
		if (c != ',' && !(c >= '0' && c <= '9')) {
			cout << "String must contain only nums separated by commas" << endl;
			return true;
		}
	}
	return false;
}
void show_user_data_for_admin(vector<int>&pos, vector<account>& arr) {
	for (int i = 0;i < pos.size();i++) {
		cout << arr[pos[i]].login << "\t";
		show_status(arr[pos[i]].role);
		cout << endl;
	}
}
void vector_sort(vector<int>&arr) {
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void vector_prep_to_del(vector<int>&arr) {
	for (int i = 0;i < arr.size();i++) {
		arr[i] -= i;
	}
}
bool num_limits(vector<int>arr,vector<account>arr_2) {
	for (int i:arr) {
		if (i >arr_2.size()-1 ) {
			cout << "We don't have this user position" << endl;
			return true;
			
		}
	}
	return false;
}