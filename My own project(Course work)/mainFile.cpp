#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;
struct Account
{
	string login;//Логин
	string password;//Пароль
	int role;//Роль
	bool status;//Статус: доступ есть или нет
};
struct Toys {
	string name;//Название игрушки
	double price;//Цена игрушки
	string producer;//Производитель игрушки
	int amount;//Количество игрушек на складе
	int ageLimit;//Возростное ограничение игрушки
};

const string USERSINFORMATION = "Users.txt";
const string TOYSINFORMATION = "ToysRange.txt";
const string ERRORWITHFILES = "Error with file";
const string ADMIN = "ADMIN";
const string ENGINEER = "Engineer";
const string GUEST = "Guest";
const string MANAGER = "Manager";
const string CUSTOMER = "Customer";
const string LOG = "Log.txt";
const string TOYSCHANGE = "Enter toy or toys position separated by commas";
const string USERCHANGE = "Enter user or users position separated by commas";
const string PROPERTIESCHANGEMENU = "Properties(input separete by commas)\n1--Change Name\n2--Change price\n3--Change age limit\n4--Change amount\n5--Change producer\n0--Exit";
const string ACCOUNTNAMELOG = "Account ";
const string ACCOUNTCREATIONLOG = " is created";
const string CHANGENAMELOG = " has changed login to ";
const string CHANGEPASSLOG = " has changed pass to ";
const string CHANGEROLELOG = " role change to ";
const string CHANGESTATUSLOG = " status changed to ";
const string DELETEACCOUNTLOG = " account is deleted";
const string TOYNAMELOG = "Toy ";
const string TOYCREATIONLOG = " is created";
const string CHANGETOYNAMELOG = "  name changed to ";
const string CHANGETOYPRICELOG = "  price changed to ";
const string CHANGETOYPRODUCERLOG = "  producer changed to ";
const string CHANGETOYAMOUNTLOG = " amount changed to ";
const string CHANGETOYAGELIMITLOG = " age limit changed to ";
const string DELETETOYLOG = " is deleted";
const string STATUSBANLOG = " banned";
const string STATUSUNBANLOG = " unbanned";
const string USERMENU = "1--Log in\n2--Registration\n3--Profile\n4--Toys menu\n0--Exit";
const string ADMINMENU = "1--Log in\n2--Registration\n3--Profile\n4--Toys menu\n5--Toys menu for admin\n6--Update user data\n7--Show users\n8--Show logs\n0--Exit";
const string LOGINASK = "Do you have an account?\n1--Yes\n2--No\n0--Exit";
const string PROFILECHOICE = "If you want to change data press 1, you want to leave that menu press 2";
const string USERCHANGINGPROFILE = "What would you like to change?\n1--Login\t2--Password\t3--Both\t4--Delete account\t0-Exit";
const string AGREEMENTRODELETE = "Are you sure that you'd like to delete account\n1--Yes\t2--No";
const string ADMINUSERDATACHANGEMENU = "What would you like to do with user/users \n1--Change Login\n2--Change Password\n3--Change login ,password\n4--Delete\n5--Change role\n6--Add user\n7--Change user status\n0--Exit";
const string ADMINAGREEMENTTODELETE = "Are you shure that you'd like to change that user/users data?\n1--yes\n2--no";
const string ADDMORETOY = "Would you like to add one/several toys more--press 1\nLive that menu--press 0";
const string ADMINTOYMENU = "1--Add toys\n2--Show toys\n3--Change toy data\n0--exit";
const string USERTOYMENU = "1--Show all toys\n2--Find toys\n3--Sort toys\n0--Exit";
const string TOYAGEDEFINE = "Enter toy age";
const string TOYSCHANGINGMENU = "Toys changing menu\n1--Change whole info\n2--Change toy property\n3--Del toy/toys\n0--Exit";
const string TOYCHANGEAGREEMENT = "Is everything correct?\n1--Yes\t2--No";
const string TOYDATACHANGEAGREEMENT = "Is everything correct(change data)?\n1--Yes\t2--No";
const string FINDMENU = "1--Search by name\n2--Search by age\n3--Search by producer\n0--Exit";
const string SORTMENU = "Chose sort type\n1--Sort by name(A-Z)\t2--Sort by name(Z-A)\t3--Sort by price(Low-High)\t4--Sort by price(High-Low)\t5--Sort by age limit(Low-High)\t6--Sort by age limit(High-Low)\t0--Exit";
const string VALIDATIONERROR= "Sorry we don't have that account,or you've created a mistake \nWhat would you like to do\n 1--Try again?\t2--Create an account?\t0--Stay as guest?";
const string USERBANMASSEGEFORADMIN = "Would you like to ban that user\n1--Yes\t2--No";
const string USERUNBANMASSEGEFORADMIN = "Would you like to unban that user\n1--Yes\t2--No";
const string ADMINAGREEMENT = "Are you shure\n1--Yes\t2--No";
const string TOYSZEROADD = "Don't you want to add toys\n1--Yes\t2--No";
const string ROLEMASSEGE = "Role:";
const string DELETEADMINMASSEGE = "You can't delete admin";
const string INCORRECTINPUT = "There are mistake,please check your input";
const string ONLYSYMBOLS = "Error!! Only Symbols(English)";
const string ONLYNUMBERS ="Error!! Only Numbers" ;
const string PASSWORDINPUT = "Password:";
const string RESERVEDNICKNAME = "You can't use that nickname,try another one, for example that one -- ";
const string EMPTYFIELDLOGIN = "Login can't be empty";
const string LOGININPUT = "Login:";
const short EXIT = 0;
const short RIGHTBOARDADMINMENU = 8;
const short RIGHTBOARDUSERMENU = 4;
const short RIGHTBOARLOGINASK = 2;
const short PROFILECHOICETRUE = 1;
const short PROFILECHOICEFALSE = 2;
const short USERMENUMARKER = 1;
const short USERCHANGINGPROFILERIGHTBOARD = 4;
const short RIGHTBOARDERVALIDATIONERROR = 2;
const short BANCHOICETRUE = 1;
const short BANCHOICEFALSE = 2;
const short UNBANCHOICETRUE = 1;
const short UNBANCHOICEFALSE = 2;
const short ADMINCHOICETRUE = 1;
const short ADMINCHOICEFALSE = 2;
const short ADMINDATACHANGEMENURIGHTBOARDER = 7;
const short ADMINMENUMARKER = 0;
const short ADMINPOSITION = 0;
const short ADDTOYSAGREEMENT = 1;
const short ADMINTOYSMENURIGHTBOARD = 3;
const short TOYMAINMENURIGHTBOARD = 3;
const short SORTMENURIGHTBOARD = 6;
const short TOYFINDMENURIGHTBOARD = 3;
const short NUMLISTOPTIONSIZE = 5;
const short CHANGENAMELOGPOS = 1;
const short CHANGEPASSLOGPOS = 2;
const short CHANGEROLELOGPOS = 3;
const short CHANGESTATUSLOGPOS = 4;
const short DELETEACCOUNTLOGPOS = 5;
const short ACCOUNTCREATIONLOGPOS = 6;
const short CHANGETOYNAMELOGPOS = 1;
const short CHANGETOYPRICELOGPOS = 2;
const short CHANGETOYAMOUNTLOGPOS = 3;
const short CHANGETOYPRODUCERLOGPOS = 4;
const short CHANGETOYAGELIMITLOGPOS = 5;
const short DELETETOYLOGPOS = 6;
const short TOYCREATIONLOGPOS = 7;
const short ADMINROLE = 0;
const short GUESTROLE = 1;
const short USERROLE = 2;
const short ACTIVE = 1;
const short BANNED = 0;
const short DELETEUSERMENU = 4;
const short ADDUSERMENU = 6;
const short ADMINROLEFORMENU = 1;
const short MINAGE = 0;
const short MAXAGE = 99;

void showLogs(vector<string>arr);
int showMenu(string str, int leftBoarder, int rightBoarder);
void validationErrorCore(vector<Account>& arr, Account& user, vector<string>& log);
void dataInput(Account& buff);
void passwordCreation(vector <Account>& arr, Account& user);
void nicknameCreation(vector <Account>& arr, Account& user);
int find_pos(vector<Toys>& arr, string name);
void logCreation(vector<Toys>toys, vector<string>& log, int type, int pos, string buffString);
string statusReturn(bool flag);
string roleReturn(int role);
void logCreation(vector<Account>accounts, vector<string>& log, int type, int pos, string buffString);
string strCreate(string strType, string strName, string strConst, string strEnd);
void writeFiles(vector<Account>& accounts, vector<Toys>& toys, vector<string>& log);
void readFiles(vector<Account>& accounts, vector<Toys>& toys, vector<string>& log);
void delToy(vector<int>numList, vector<Toys>& toys,vector<string>&log);
void numListMinusOne(vector<int>& numList);
void changeToyInfoCore(vector<Toys>& toys, vector<string>& log);
int toyChangeAgeLimit();
double toyChangePrice();
string toyChangeName();
string toyChangeProducer();
void changeToyProperty(vector<Toys>& arr, int pos,vector<string>& log);
bool adminCheck(vector<int>numList);
bool checkNumListForDuple(vector<int>numList);
void toyChangingByPos(vector<Toys>& toys, int pos, vector<string>& log);
void numListCreating(vector<int>& numList, string str, int arrSize,bool flag);
void toyInputData(Toys& buff);
void showToy(Toys toy);
void vector_sort_from_max_min_price(vector<Toys>& arr);
void vector_sort_from_min_max_price(vector<Toys>& arr);
void vector_sort_from_max_min_toys_by_name(vector<Toys>& arr);
void vector_sort_from_min_max_toys_by_name(vector<Toys>& arr);
void binar_search(vector<string> arr, string str, int& answer);
void vector_sort_from_max_min_age(vector<Toys>& arr);
void vector_sort_from_min_max_age(vector<Toys>& arr);
void userStatusChange(vector<Account>&arr, int position);
void showToys(vector<Toys>& toys);
void toysMenuCore(vector<Toys>& toys, vector<string>& log);
void write_file_toys(vector <Toys>& arr);
void read_file_toys(vector <Toys>& arr);
void input_toys_information(vector<Toys>&toys, vector<string>& log);
void toys_range_creation(vector<Toys>&toys, vector<string>& log);
bool num_limits(vector<int>arr, vector<Account>arr_2);
void admin_menu(Account& user, vector<Account>& arr, vector<string>& log);
void vector_sort_from_min_max(vector<int>& arr);
void vector_prep_to_del(vector<int>& arr);
void show_users_data_for_admin(vector<int>& pos, vector<Account>& arr);
void guest_creation(Account& user);
void account_info(Account& user, vector<Account>& arr, vector<string>& log);
void show_role(int role);
void account_entering(vector<Account>& arr,Account&user, vector<string>& log);
bool is_data_valid(vector<Account>& arr, Account& user);
void log_in(Account& user, vector <Account>& arr, vector<string>& log);
void account_creation(vector <Account>& arr,Account& user, vector<string>& log);
void core(vector <Account>& arr,vector<Toys>&toys,vector<string>&log);
bool compare(string& str1, string& str2);
bool check_empty();
bool check();
bool check_str(string& str);
void del_user(vector <Account>& arr, int choice,Account&user,int menu);
void show_data(vector <Account>& arr);
void write_file(vector <Account>& arr);
void read_file(vector <Account>& arr, vector<string>& log);
int find_pos(vector<Account>& arr, string login);
void data_change(Account& user, int choice, vector<Account>& arr, int position,int menu, vector<string>& log);
bool login_compare(vector<Account>& arr, string login);
string login_creation(string false_login);
void user_information_change(Account& user, int choice, vector<Account>& arr, int position,int menu, vector<string>& log);
bool check_str_for_num(string str);
void user_position_data(string str, vector<int>& num_list);
void role_change(vector<Account>arr, int position, int choice);
void password_change(vector<Account>& arr, int position);
void login_change(vector<Account>& arr, int position);
void showToys(vector<Toys>& toys);
void show_user_data_for_admin(vector<Account>& arr, int i);
void findMenuCore(vector<Toys>arr);
void sortMenuCore(vector<Toys>& arr);
void searchResult(int answer, vector<Toys>arr);
vector<string> stringVectorCreateProducer(vector<Toys>& arr);
void mainToysMenuCore(vector<Toys>& arr);

int main() {
	vector <Account> arr;
	vector<Toys>toys;
	vector<string>log;
	readFiles(arr,toys,log);
	core(arr,toys,log);
	writeFiles(arr,toys,log);
	return 0;
}
void core(vector <Account>& arr,vector<Toys>&toys,vector<string>&log) {
	Account user;
	guest_creation(user);
	while (true) {
		system("cls");
		switch (user.role==ADMINROLE? showMenu(ADMINMENU,EXIT,RIGHTBOARDADMINMENU) :showMenu(USERMENU,EXIT,RIGHTBOARDUSERMENU)) {
		case 1: log_in(user,arr,log);
			break;
		case 2: account_creation(arr,user,log);
			break;
		case 3: account_info(user, arr,log);
			break;
		case 4:mainToysMenuCore(toys);
			break;
		case 5:toysMenuCore(toys,log);
			break;
		case 6:admin_menu(user, arr,log);
			break;
		case 7:show_data(arr);
			break;
		case 8:showLogs(log);
			break;
		case 0:return;
		default:cout <<INCORRECTINPUT<< endl;
			break;
		}
	}
}
int showMenu(string str,int leftBoarder,int rightBoarder) {
	int choice;
	do {
		cout << str<< endl;
		cin >> choice;
	} while (check() || (choice < leftBoarder && choice> rightBoarder));
	return choice;
}
void del_user(vector <Account>& arr,int position,Account&user,int menu) {

	if (position != ADMINPOSITION) {
		arr.erase(arr.begin() + position);
	}
	if (user.role != ADMINROLE && menu != ADMINMENUMARKER) {

		guest_creation(user);
	}
	else {
		if (menu != ADMINMENUMARKER) {
			cout << DELETEADMINMASSEGE << endl;
		}
	}

}
void show_data(vector <Account>& arr) {

	cout << "\t\t\t\tUser data:" << endl;
	for (int i = 0;i < arr.size();i++) {
		cout << i << ")" << "Log:" << arr[i].login << endl;
	}
	cout << "\n" << endl;
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
		cout << ONLYSYMBOLS << endl;
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
		cout << ONLYNUMBERS << endl;
		return true;
	}
}
void writeLogFile(vector <string>&arr) {
	ofstream fout;
	fout.open(LOG);
	if (!(fout.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else {
		for (int i = 0;i < arr.size();i++) {
			fout << arr[i];
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
void write_file(vector <Account>& arr) {
	ofstream fout;
	fout.open(USERSINFORMATION);
	if (!(fout.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else {
		for (int i = 0;i < arr.size();i++) {
			fout << arr[i].login << "\n" << arr[i].password << "\n" << arr[i].role<<"\n" << arr[i].status;
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
void write_file_toys(vector <Toys>& arr) {
	ofstream fout;
	fout.open(TOYSINFORMATION);
	if (!(fout.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else {
		for (int i = 0;i < arr.size();i++) {
			fout << arr[i].name << "\n" << arr[i].producer << "\n" << arr[i].price<<"\n" <<arr[i].amount<<"\n"<<arr[i].ageLimit;
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
void writeFiles(vector<Account>&accounts, vector<Toys>&toys, vector<string>&log) {
	write_file(accounts);
	write_file_toys(toys);
	writeLogFile(log);
}
void readLogFile(vector <string>& arr) {
	ifstream fin;
	string buff;
	fin.open(LOG);
	if (!(fin.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else {
		for (int i = 0;!(fin.eof());i++) {

			getline(fin, buff);
			if (!(buff.empty())) {
				arr.push_back(buff);
			}
			else {
				break;
			}

		}
	}
	fin.close();
}
void read_file(vector <Account>& arr,vector<string>&log) {
	ifstream fin;
	Account account;

	fin.open(USERSINFORMATION);
	if (!(fin.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else if (check_empty()) {
		account.login = "admin";
		account.password = "admin";
		account.role = ADMINROLE;
		account.status = 1;
		arr.push_back(account);
		logCreation(arr,log, ACCOUNTCREATIONLOGPOS,ADMINPOSITION,"");
	}
	else {
		for (int i = 0;!(fin.eof());i++) {

			getline(fin, account.login);
			getline(fin, account.password);
			fin >> account.role;
			fin >> account.status;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!(account.login.empty())) {
				arr.push_back(account);
			}
			else {
				break;
			}

		}
	}
	fin.close();
}
void read_file_toys(vector <Toys>& arr) {
	ifstream fin;
	Toys toy;

	fin.open(TOYSINFORMATION);
	if (!(fin.is_open())) {
		cout << ERRORWITHFILES << endl;
	}
	else 
		for (int i = 0;!(fin.eof());i++) {

			getline(fin, toy.name);
			getline(fin, toy.producer);
			fin>>toy.price;
			fin >> toy.ageLimit;
			fin >> toy.amount;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!(toy.name.empty())) {
				arr.push_back(toy);
			}
			else {
				break;
			}

		}
	
	fin.close();
}
void readFiles(vector<Account>& accounts, vector<Toys>& toys, vector<string>& log) {
	read_file(accounts,log);
	read_file_toys(toys);
	readLogFile(log);
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
void log_in(Account& user, vector <Account>& arr,vector<string>&log) {
	short choice;
	switch (showMenu(LOGINASK,EXIT,RIGHTBOARLOGINASK)) {
	case 1: account_entering(arr,user,log);
		break;
	case 2: account_creation(arr,user,log);
		break;
	default:;
	}
}
void account_creation(vector <Account>& arr,Account&user,vector<string>&log) {
	Account buff = user;
	system("cls");
	passwordCreation(arr,user);
	user.role = USERROLE;
	user.status = ACTIVE;
	arr.push_back(user);
	logCreation(arr,log, ACCOUNTCREATIONLOGPOS,find_pos(arr,user.login),"");
	if (buff.role==ADMINROLE) {
		user = buff;
	}
}
void passwordCreation(vector <Account>& arr, Account& user) {
	do {
		nicknameCreation(arr,user);
		cout << PASSWORDINPUT;
		cin >> user.password;
	} while (check_str(user.login));
}
void nicknameCreation(vector <Account>& arr,Account &user) {
	do {
		cout << LOGININPUT;
		getline(cin, user.login);
		if (login_compare(arr, user.login)) {
			cout << RESERVEDNICKNAME << login_creation(user.login) << endl;
		}

		if (user.login.empty()) {
			cout << EMPTYFIELDLOGIN << endl;
		}

	} while (login_compare(arr, user.login) || user.login.empty());
}
bool is_data_valid(vector<Account>& arr, Account& user) {
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
void account_entering(vector<Account>& arr,Account&user, vector<string>& log) {
	Account buff;
	while (1) {
		dataInput(buff);
		if (is_data_valid(arr, buff)) {
			if (arr[find_pos(arr, buff.login)].status) {
				user = arr[find_pos(arr, buff.login)];
			}
			else {
				cout << "This account is blocked,connect admin or other moderator" << endl;
			}
			break;
		}
		else {
			validationErrorCore(arr,user,log);
		}
	}	
}
void dataInput(Account&buff) {
	cout << "Log:";
	getline(cin, buff.login);
	cout << "Password:";
	cin >> buff.password;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void validationErrorCore(vector<Account>& arr, Account& user, vector<string>& log) {
	switch (showMenu(VALIDATIONERROR,EXIT,RIGHTBOARDERVALIDATIONERROR)) {
	case 1:;
		break;
	case 2: account_creation(arr, user, log);
		break;
	case 0:	user.login = "guest";
		user.password = 1;
		user.role = GUESTROLE;
		user.status = ACTIVE;
		break;
	}
}
void account_info(Account& user, vector<Account>& arr, vector<string>& log) {
	cout << "Profile information\nLogin:" << user.login << "\nPassword:" << user.password << endl;
	cout << "Status:";
	show_role(user.role);
	if (user.role!=GUESTROLE) {
		if (showMenu(PROFILECHOICE, PROFILECHOICETRUE, PROFILECHOICEFALSE) == PROFILECHOICETRUE) {
			data_change(user, showMenu(USERCHANGINGPROFILE,EXIT,USERCHANGINGPROFILERIGHTBOARD), arr, find_pos(arr, user.login), USERMENUMARKER, log);
		}

	}
	else {
	
		cout << "If you want to leave that menu press any bottom" << endl;

		system("pause");

	}
}
void show_role(int role) {
	switch (role) {
	case 0:cout << ADMIN << endl;
		break;
	case 1:cout << GUEST << endl;;
		break;
	case 2:cout<<CUSTOMER<<endl;
		break;
	}
}
int find_pos(vector<Account>& arr, string login) {
	
	for (int i = 0;i < arr.size();i++) {
		if (compare(arr[i].login,login)) {
			return i;
		}
	}
	
}
int find_pos(vector<Toys>& arr, string name) {

	for (int i = 0;i < arr.size();i++) {
		if (compare(arr[i].name, name)) {
			return i;
		}
	}

}
void data_change(Account &user,int choice,vector<Account>&arr,int position,int menu, vector<string>& log) {
	user_information_change(user, choice,arr,position,menu,log);
	if (menu !=ADMINMENUMARKER&&choice!=DELETEUSERMENU) {
		user = arr[position];
	}
}
void guest_creation(Account&user) {
	user.login = "Guest";
	user.password = 1;
	user.role = GUESTROLE;
	user.status = ACTIVE;
}
bool login_compare(vector<Account>& arr, string login) {
	for (int i = 0;i < arr.size();i++) {
		if (!compare(arr[i].login, login)) {
			if (i == (arr.size() - 1)) {
				return false;
			}
		}
		else {
			return true;
		}
		
	}
	return false;
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
void user_information_change(Account& user, int choice,vector<Account>&arr,int pos,int menu, vector<string>& log) {
	int confirmation=2;
	string buffName;
	switch (choice) {
	case 1:buffName = arr[pos].login;
		login_change(arr, pos);
		logCreation(arr, log, CHANGENAMELOGPOS, pos, buffName);
		break;
	case 2:password_change(arr, pos);
		logCreation(arr, log, CHANGEPASSLOGPOS, pos, "");
		break;
	case 3:buffName = arr[pos].login;
		login_change(arr, pos);
		password_change(arr, pos);
		logCreation(arr, log, CHANGENAMELOGPOS, pos, buffName);
		logCreation(arr, log, CHANGEPASSLOGPOS, pos, "");
		break;
	case 4:
		if (menu != ADMINMENUMARKER) {
			confirmation = showMenu(AGREEMENTRODELETE, PROFILECHOICETRUE, PROFILECHOICEFALSE);
		}
		if (confirmation == 1 || menu == ADMINMENUMARKER) {
			logCreation(arr, log, DELETEACCOUNTLOGPOS, pos, "");
			del_user(arr, pos, user, menu);
		}
		break;
	case 5:role_change(arr, pos, choice);
		logCreation(arr, log, DELETEACCOUNTLOGPOS, pos, "");
		break;
	case 6:account_creation(arr, user, log);
		break;
	case 7:userStatusChange(arr, pos);
		logCreation(arr, log, CHANGESTATUSLOGPOS,pos, "");
		break;
	case 0:return;
	}
	if (menu != ADMINMENUMARKER) {
		cout << "mission complited!" << endl;
	}
}
void userStatusChange(vector<Account>&arr,int position) {
	int choice;
	show_user_data_for_admin(arr,position);
	if (arr[position].status) {
		if (showMenu(USERBANMASSEGEFORADMIN,BANCHOICETRUE,BANCHOICEFALSE) == BANCHOICETRUE) {
			if (showMenu(ADMINAGREEMENT,ADMINCHOICETRUE,ADMINCHOICEFALSE) == ADMINCHOICETRUE) {
				arr[position].status = false;
			}
		}
	}
	else {
		if (showMenu(USERUNBANMASSEGEFORADMIN, UNBANCHOICETRUE, UNBANCHOICEFALSE) == UNBANCHOICETRUE) {
			if (showMenu(ADMINAGREEMENT, ADMINCHOICETRUE, ADMINCHOICEFALSE) == ADMINCHOICETRUE) {
				arr[position].status = true;
			}
		}
	}
	
}
void admin_menu(Account& user, vector<Account>& arr, vector<string>& log) {
	int choice;
	string user_pos_string;
	vector<int>num_list;
	system("cls");
	choice = showMenu(ADMINUSERDATACHANGEMENU,EXIT,ADMINDATACHANGEMENURIGHTBOARDER);
	if (choice!=EXIT) {
		if (choice==ADDUSERMENU) {
			data_change(user, choice, arr, ADMINPOSITION, ADMINMENUMARKER,log);
		}
		else {
			do {
				num_list.clear();
				show_data(arr);
				numListCreating(num_list,USERCHANGE,arr.size(),false);
				if (adminCheck(num_list)) {
					num_list.clear();
					continue;
				}
				show_users_data_for_admin(num_list, arr);
			} while (showMenu(ADMINAGREEMENTTODELETE, ADMINCHOICETRUE,ADMINCHOICEFALSE) == ADMINCHOICEFALSE);
			if (choice == DELETEUSERMENU) {
				vector_sort_from_min_max(num_list);
				vector_prep_to_del(num_list);
			}
			for (int i : num_list) {
				data_change(user, choice, arr, i, ADMINMENUMARKER,log);
			}
			num_list.clear();
		}
		cout << "mission complited" << endl;
	}
}
bool adminCheck(vector<int>numList) {
	for (int i:numList) {
		if (i==ADMINPOSITION) {
			cout << "You can't do something with admin at that menu but you can try use \"Profile\"" << endl;
			return true;
		}
	}
	return false;
}
void show_role_menu() {
	cout<<"1--Admin\n2--Customer" << endl;
}
void user_position_data(string str, vector<int>& num_list) {
	int num_len = 0, num = 0,buff;

	for (int i = 0;i <= str.size();i++) {
		if (str[i] != ',' && str[i] != '\0') {
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

	for (char c : str) {
		if (c != ',' && !(c >= '0' && c <= '9')) {
			cout << "String must contain only nums separated by commas" << endl;
			return true;
		}
	}
	return false;
}
void show_users_data_for_admin(vector<int>&pos, vector<Account>& arr) {
	for (int i = 0;i < pos.size();i++) {
		show_user_data_for_admin(arr,pos[i]);
	}
}
void show_user_data_for_admin(vector<Account>& arr,int i) {
		cout << arr[i].login << "\t" << arr[i].password << "\t";
		if (arr[i].status) {
			cout << "Active" << "\t";

		}
		else {
			cout << "Blocked" << "\t";
		}
		show_role(arr[i].role);
	
}
void vector_sort_from_min_max(vector<int>&arr) {
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void vector_sort_from_min_max_age(vector<Toys>& arr) {
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j].ageLimit > arr[j + 1].ageLimit) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void vector_sort_from_max_min_age(vector<Toys>& arr) {
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j].ageLimit < arr[j + 1].ageLimit) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void vector_sort_from_min_max_price(vector<Toys>& arr) {
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j].price > arr[j + 1].price) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void vector_sort_from_max_min_price(vector<Toys>& arr) {
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j].price < arr[j + 1].price) {
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
bool num_limits(vector<int>arr,vector<Account>arr_2) {
	for (int i:arr) {
		if (i >arr_2.size()-1 ) {
			cout << "We don't have this user position" << endl;
			return true;
			
		}
	}
	return false;
}
void login_change(vector<Account>& arr, int position) {
	Account buff;
	buff = arr[position];
	do {
		cout << "Log:";
		getline(cin, arr[position].login);
		
		if (arr[position].login.empty()) {
			cout << "String can't be empty" << endl;
		}
		else {
			cout << "Now " << buff.login << " is " << arr[position].login << endl;
		}
	} while (arr[position].login.empty());
}
void password_change(vector<Account>& arr, int position) {
	Account buff;
	buff = arr[position];
	do {
		cout << "Password:";
		cin >> arr[position].password;
		if (arr[position].password == buff.password) {
			cout << "Don't use previose password" << endl;
		}
	} while (arr[position].password==buff.password);
	cout << "Now " << buff.login << " password changed to " << arr[position].password << endl;
}
void role_change(vector<Account>arr,int position,int choice) {
	int buff;
	show_role_menu();
	cout << "Role:" << endl;
	do
	{
		cin >> buff;

	} while (check() || (buff < 1 && buff > 2));

	if (showMenu(ROLEMASSEGE,ADMINROLEFORMENU,USERROLE) == ADMINROLEFORMENU) {
		arr[position].role = ADMINROLE;
	}
	else {
		arr[position].role = USERROLE;
	}
	cout << "Now " << arr[position].login << " is ";
	show_role(arr[position].role);
}
void toys_range_creation(vector<Toys>&toys,vector<string>&log) {
	int choice=0;
	do {
		do {
			cout << "How much toys you'd like to add" << endl;
			cin >> choice;
			if (choice == 0) {
				if (showMenu(TOYSZEROADD, ADMINCHOICETRUE, ADMINCHOICEFALSE) ==ADMINCHOICETRUE) {
					return;
				}
			}
		} while (check() || choice < 1);
		
			for (int i = 0;i < choice;i++) {
				input_toys_information(toys,log);
			}
		
	} while (showMenu(ADDMORETOY,EXIT,ADDTOYSAGREEMENT) == ADDTOYSAGREEMENT);
}
void input_toys_information(vector<Toys>&toys, vector<string>& log) {
	Toys buff;
	short choice;
	while(1){
		toyInputData(buff);
		if (showMenu(TOYSCHANGINGMENU,ADMINCHOICETRUE,ADMINCHOICEFALSE) == ADMINCHOICETRUE) {
			toys.push_back(buff);
			logCreation(toys,log, TOYCREATIONLOGPOS,find_pos(toys,buff.name),"");
			break;
		}
	}
}
void toyInputData(Toys& buff) {
	system("cls");
	buff.name = toyChangeName();
	buff.producer = toyChangeProducer();
	buff.price = toyChangePrice();
	buff.ageLimit = toyChangeAgeLimit();
	buff.producer = toyChangeProducer();
}
void showToys(vector<Toys>& toys) {
	if (!toys.empty()) {
		for (Toys toy : toys) {
			showToy(toy);
		}
	}
	else {
		cout << "There are no toys" << endl;
	}
}
void showToy(Toys toy) {
	cout << "Toy name:" << toy.name << "\tToy producer:" << toy.producer << "\tToy price:" << toy.price << "\tToy age limit:" << toy.ageLimit << "\tAmount of toys:" << toy.amount << endl;
}
void toysMenuCore(vector<Toys>& toys, vector<string>& log) {
	switch (showMenu(ADMINTOYMENU,EXIT,ADMINTOYSMENURIGHTBOARD)) {
	case 1:toys_range_creation(toys,log);
		vector_sort_from_min_max_toys_by_name(toys);
		break;
	case 2:showToys(toys);
		break;
	case 3:changeToyInfoCore(toys,log);
		break;
	default:return;
	}
}
void vector_sort_from_min_max_toys_by_name(vector<Toys>& arr) {
	if (!arr.empty()) {
		for (int i = 0;i < arr.size();i++) {
			for (int j = 0;j < arr.size() - 1;j++) {
				if (arr[j].name > arr[j + 1].name) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	else {
		cout << "There are no toys" << endl;
	}
}
void vector_sort_from_max_min_toys_by_name(vector<Toys>& arr) {
	if(!arr.empty()){
	for (int i = 0;i < arr.size();i++) {
		for (int j = 0;j < arr.size() - 1;j++) {
			if (arr[j].name < arr[j + 1].name) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
	else {
	cout << "There are no toys" << endl;
	}
}
void mainToysMenuCore(vector<Toys>& arr) {

	while (1) {
		switch (showMenu(USERTOYMENU,EXIT,TOYMAINMENURIGHTBOARD))
		{
		case 1:showToys(arr);
			break;
		case 2:findMenuCore(arr);
			break;
		case 3:sortMenuCore(arr);
			break;
		default:return;
			break;
		}
	}
}
void searchToysByAgeGroup(vector<Toys>&arr,int toyRange) {
	for (Toys toy : arr) {
		if (toy.ageLimit<=toyRange) {
			showToy(toy);
		}
	}
}
void binar_search(vector<string> arr, string str, int& answer) {
	int left, mid, right, buff;

	left = 0;
	right = arr.size() - 1;
	bool flag = true;
	while (left <= right && flag) {
		mid = (left + right) / 2;
		buff = arr[mid].compare(str);
		switch (buff) {
		case 1:right = mid - 1;
			break;
		case 0:answer = mid;
			flag = false;
			break;
		case -1:left = mid + 1;
			break;

		}
	}
}
void searchToys(vector<Toys>&arr,vector<string>arrString,string str) {
	int answer = -1;
	vector_sort_from_min_max_toys_by_name(arr);
	binar_search(arrString, str, answer);
	searchResult(answer,arr);
}
string searchStringInputName() {
	string str;
	cout << "Enter toy name:";
	getline(cin, str);
	return str;
}
string searchStringInputProducer() {
	string str;
	cout << "Enter toy producer:";
	getline(cin, str);
	return str;
}
vector<string> stringVectorCreateName(vector<Toys>& arr) {
	vector<string>arrString;
	for (Toys toy : arr) {
		arrString.push_back(toy.name);
	}
	return arrString;
}
vector<string> stringVectorCreateProducer(vector<Toys>& arr) {
	vector<string>arrString;
	for (Toys toy : arr) {
		arrString.push_back(toy.producer);
	}
	return arrString;
}
void searchResult(int answer, vector<Toys>arr) {
	if (answer >= 0) {
		cout << "Answer is:";
		showToy(arr[answer]);
	}
	else {
		cout << "There are no need string" << endl;
	}
}
void sortMenuCore(vector<Toys>& arr) {
	while (1) {
		switch (showMenu(SORTMENU,EXIT,SORTMENURIGHTBOARD)) {
		case 1:vector_sort_from_min_max_toys_by_name(arr);
			showToys(arr);
			break;
		case 2:vector_sort_from_max_min_toys_by_name(arr);
			showToys(arr);
			break;
		case 3:vector_sort_from_min_max_price(arr);
			showToys(arr);
			break;
		case 4:vector_sort_from_max_min_price(arr);
			showToys(arr);
			break;
		case 5:vector_sort_from_min_max_age(arr);
			showToys(arr);
			break;
		case 6:vector_sort_from_max_min_age(arr);
			showToys(arr);
			break;
		default:return;
		}
	}
}
void findMenuCore(vector<Toys>arr) {
	bool flag = true;
	while (flag) {
		switch (showMenu(FINDMENU,EXIT,TOYFINDMENURIGHTBOARD)) {
		case 1:searchToys(arr, stringVectorCreateName(arr), searchStringInputName());
			break;
		case 2:searchToysByAgeGroup(arr,showMenu(TOYAGEDEFINE,MINAGE,MAXAGE));
			break;
		case 3:searchToys(arr, stringVectorCreateProducer(arr), searchStringInputProducer());
			break;
		default:flag = false;
			break;
		}
	}
}
bool checkNumList(vector<int>numList,int arrSize) {
	for(int i:numList){
		if (i<0||i>arrSize-1) {
			cout << "Please check your input" << endl;
			return true;
		}
	}
	return false;
}
void changeToyInfoCore(vector<Toys>&toys, vector<string>& log) {
	if (!toys.empty()) {
		vector<int>numList;
		showToys(toys);
		numListCreating(numList, TOYSCHANGE, toys.size(),true);
		switch (showMenu(TOYSCHANGINGMENU,EXIT,ADMINTOYSMENURIGHTBOARD)) {
		case 1:for (int i : numList) {
			toyChangingByPos(toys, i - 1,log);	
		}
		break;
		case 2:for (int i : numList) {
			changeToyProperty(toys,i,log);
		}
			break;
		case 3:delToy(numList,toys,log);
			break;
		case 0:return;
		}
		numList.clear();
	}
}
void delToy(vector<int>numList,vector<Toys>&toys,vector<string>&log) {
	vector_sort_from_min_max(numList);
	vector_prep_to_del(numList);
	for (int i:numList) {
		logCreation(toys, log, DELETETOYLOGPOS, i, "");
		toys.erase(toys.begin() + i);
	}
}
bool checkNumListForDuple(vector<int>numList) {
	for (int i = 0;i < numList.size();i++) {
		if (i!=numList.size() - 1) {
			for (int j = i + 1;j < numList.size();j++) {
				if (numList[i] == numList[j]) {
					cout << "You can't write the same numbers" << endl;
					return true;
				}
			}
		}
	}
	return false;
}
void numListCreating(vector<int>&numList,string str,int arrSize,bool flag) {
	string position;
	do {
		do {
			cout <<str << endl;
			getline(cin, position);
		} while (check_str_for_num(position));
		if (position.empty()) {
		numList.clear();
		}	
		user_position_data(position, numList);
		if (flag) {
			numListMinusOne(numList);
		}
		if (checkNumListForDuple(numList)||checkNumList(numList, arrSize)) {
			numList.clear();
		}
	} while (numList.empty());
	
}
void numListMinusOne(vector<int>&numList) {
	for (int &i:numList) {
		i -= 1;
	}
}
void toyChangingByPos(vector<Toys>& toys, int pos,vector<string>&log) {
	Toys buff;
	short choice;
	while (1) {
		toyInputData(buff);
		if (showMenu(TOYCHANGEAGREEMENT,ADMINCHOICETRUE,ADMINCHOICEFALSE) == ADMINCHOICETRUE) {
			toys[pos] = buff;
			logCreation(toys, log, TOYCREATIONLOGPOS, find_pos(toys, buff.name), "");
			break;
		}
	}
}
string toyChangeName() {
	string str;
	cout << "Enter toy name:";
	getline(cin, str);
	return str;
}
double toyChangePrice() {
    double buff;
	do {
		cout << "Enter toy price:";
		cin >> buff;
	} while (check() || buff < 0);
	return buff;
}
int toyChangeAgeLimit() {
	int buff;
	do {
		cout << "Enter minimal age limit(only numbers):";
		cin >> buff;
	} while (check() || (buff < MINAGE && buff>MAXAGE));
	return buff;
}
int toyChangeAmount() {
	int buff;
	do {
		cout << "Enter amount of toys(only numbers):";
		cin >> buff;
	} while (check() || buff < 0);
	return buff;
}
string toyChangeProducer() {
	string buff;
	cout << "Enter toy producer:";
	getline(cin, buff);
	return buff;
}
void changeToyProperty(vector<Toys>& arr, int pos,vector<string>&log) {
	vector<int>property;
	int choice;
	Toys buff = arr[pos];
	string buffString = arr[pos].name;
	while (1)
	{
		numListCreating(property, PROPERTIESCHANGEMENU, NUMLISTOPTIONSIZE,false);

		for (int i : property) {
			switch (i) {
			case 1:buff.name = toyChangeName();
				logCreation(arr,log, CHANGETOYNAMELOGPOS,pos,buffString);
				break;
			case 2:buff.price = toyChangePrice();
				logCreation(arr, log, CHANGETOYPRICELOGPOS, pos, "");
				break;
			case 3:buff.ageLimit = toyChangeAgeLimit();
				logCreation(arr, log, CHANGETOYAGELIMITLOGPOS, pos, "");
				break;
			case 4:buff.amount = toyChangeAmount();
				logCreation(arr, log, CHANGETOYAMOUNTLOGPOS, pos, "");
				break;
			case 5:buff.producer = toyChangeProducer();
				logCreation(arr, log, CHANGETOYPRODUCERLOGPOS, pos, "");
				break;
			case 0:return;
			}
		}
		showToy(buff);
		if (showMenu(TOYDATACHANGEAGREEMENT,ADMINCHOICETRUE,ADMINCHOICEFALSE) == ADMINCHOICETRUE) {
			arr[pos] = buff;
			return;
		}
		else {
			property.clear();
		}
	}
}
string strCreate(string strType,string strName,string strConst,string strEnd) {
	string buffLog;
	buffLog = strType;
	buffLog.append(strName);
	buffLog.append(strConst);
	buffLog.append(strEnd);
	return buffLog;
}
void logCreation(vector<Account>accounts,vector<string>&log,int type,int pos,string buffString) {
	string buffLog;
	switch (type) {
	case 1:buffLog=strCreate(ACCOUNTNAMELOG,buffString,CHANGENAMELOG, accounts[pos].login);
		break;
	case 2:buffLog=strCreate(ACCOUNTNAMELOG, accounts[pos].login, CHANGEPASSLOG, accounts[pos].password);
		break;
	case 3:buffLog = strCreate(ACCOUNTNAMELOG, accounts[pos].login, CHANGEROLELOG, roleReturn(accounts[pos].role));
		break;
	case 4:buffLog = strCreate(ACCOUNTNAMELOG, accounts[pos].login, CHANGESTATUSLOG, statusReturn(accounts[pos].status));
		break;
	case 5:buffLog= strCreate(ACCOUNTNAMELOG, accounts[pos].login, DELETEACCOUNTLOG,"");
		break;
	case 6:buffLog = strCreate(ACCOUNTNAMELOG, accounts[pos].login, ACCOUNTCREATIONLOG, "");
		break;
	}
	log.push_back(buffLog);
}
void logCreation(vector<Toys>toys, vector<string>& log, int type, int pos, string buffString) {
	string buffLog;
	switch (type) {
	case 1:buffLog = strCreate(TOYNAMELOG, buffString, CHANGETOYNAMELOG, toys[pos].name);
		break;
	case 2:buffLog = strCreate(TOYNAMELOG, toys[pos].name, CHANGETOYPRICELOG, to_string(toys[pos].price));
		break;
	case 3:buffLog = strCreate(TOYNAMELOG, toys[pos].name, CHANGETOYAMOUNTLOG, to_string(toys[pos].amount));
		break;
	case 4:buffLog = strCreate(TOYNAMELOG, toys[pos].name, CHANGETOYPRODUCERLOG, toys[pos].producer);
		break;
	case 5:buffLog = strCreate(TOYNAMELOG, toys[pos].name, CHANGETOYAGELIMITLOG, to_string(toys[pos].ageLimit));
		break;
	case 6:buffLog = strCreate(TOYNAMELOG, toys[pos].name, DELETETOYLOG, "");
		break;
	case 7:buffLog=strCreate(TOYNAMELOG,toys[pos].name,TOYCREATIONLOG,"");
		break;
	}
	log.push_back(buffLog);
}
string roleReturn(int role) {
	switch (role) {
	case 0:return ADMIN;
	case 1:return GUEST;
	case 2:return CUSTOMER;

	default:return "Empty";
	}
}
string statusReturn(bool flag) {
	return flag ? STATUSUNBANLOG : STATUSBANLOG;
}
void showLogs(vector<string>arr) {
	if (arr.empty()) {
		cout << "There are no logs!" << endl;
	}
	else {
	for (string in : arr){
		cout << in << endl;
	}
	}
	system("pause");
}