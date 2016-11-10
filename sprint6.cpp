
#include <string>
#include <cctype>
#include <vector>
#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.h>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>
using namespace std;

class robot_part
{
protected:
	string robot_part_name;
	string part_number;
	string discription;
	double cost;
	double weight;
public:
	robot_part(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight)
		:robot_part_name(Robot_part_name), part_number(Part_number), discription(Discription), cost(Cost), weight(Weight) {}
	string robot_Part()
	{
		return robot_part_name;
	}
	string robot_part_number()
	{
		return part_number;
	}
	string robot_discription()
	{
		return discription;
	}
	double robot_cost()
	{
		return cost;
	}
	double robot_weight()
	{
		return weight;
	}
};

class Arm : public robot_part
{
private:
	double power_consumed;
	int number_of_arms;
public:
	Arm(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight, double power_Consumed, int Number_of_arms)
		: robot_part(Robot_part_name, Part_number, Discription, Cost, Weight), number_of_arms(Number_of_arms),power_consumed(power_Consumed){}
	double powerConsumed()
	{
		return power_consumed;
	}
	int no_of_arms()
	{
		return number_of_arms;
	}
	void arm_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Part power consumption:" << power_consumed << endl;
		cout << "number of arms:" << number_of_arms << endl;
	}
};
class Head : public robot_part
{
private:
	string head;
public:
	Head(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight)
		:robot_part(Robot_part_name, Part_number, Discription, Cost, Weight) {}
	void head_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
	}
};
class Battery : public robot_part
{
private:
	double energy;
	double max_power;
public:
	Battery(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight, double eNergy, double max_pOwer)
		: robot_part(Robot_part_name, Part_number, Discription, Cost, Weight), energy(eNergy), max_power(max_pOwer) {}
	double batery_energy()
	{
		return energy;
	}
	double battery_max_power()
	{
		return max_power;
	}
	void battery_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Battery energy:" << energy << endl;
		cout << "Battery max_power:" << max_power << endl;
	}
};
class Locomotor : public robot_part
{
private:
	double max_speed;
	double consumed_power;
public:
	Locomotor(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight, double mAx_speed, double cOnsumed_power)
		:robot_part(Robot_part_name, Part_number, Discription, Cost, Weight), max_speed(mAx_speed), consumed_power(cOnsumed_power) {}
	double Max_speed()
	{
		return max_speed;
	}
	double Consumed_power()
	{
		return consumed_power;
	}
	void locomotor_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "max speed:" << max_speed << endl;
		cout << "power consumed:" << consumed_power << endl;
	}
};
class Torso : public robot_part
{
private:
	int number_of_battery;
public:
	Torso(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight, int Number_of_battery)
		: robot_part(Robot_part_name, Part_number, Discription, Cost, Weight), number_of_battery(Number_of_battery) {}
	void torso_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "number of battery:" << number_of_battery << endl;
	}
};
class robotModel
{
private:
	string name_model;
	int number_model;
	double price_model;
	string track_status;
public:
	robotModel(string Name_model, int Number_model, double Price_model, string Track_status)
		:name_model(Name_model), number_model(Number_model), price_model(Price_model), track_status(Track_status) {}
	void change_status(string changed_value)
	{
		track_status = changed_value;
	}
	void model_details()
	{
	cout << "model name:" << name_model << endl;
	cout << "model number:" << number_model << endl;
	cout << "model price:" << price_model << endl;
	cout << "This model is:" << track_status << endl;
	}
};

class customer
{
private:
	string customer_name;
	string customer_number;
	double wallet;
public:
	customer(string Customer_name, string Customer_number, double Wallet)
		:customer_name(Customer_name), customer_number(Customer_number), wallet(Wallet) {}
	void enter_customer_details()
	{
		cout << "please enter customer name:";
		cin >> customer_name;
		cin.ignore();
		cout << "please enter customer number:";
		cin >> customer_number;
		cin.ignore();
		cout << "please enter wallet number:";
		cin >> wallet;
		cin.ignore();
		cout << endl;
	}
	void customer_record()
	{
		cout << endl;
		cout << "customer name:" << customer_name;
		cout << "   customer number:" << customer_number;
		cout << "   wallet number:" << wallet << endl;
	}
};
class sales_associate
{
private:
	string associate_name;
	int employee_ID;
public:
	sales_associate(string Associate_name, int Employee_ID)
		:associate_name(Associate_name), employee_ID(Employee_ID) {}
	void enter_associate_details()
	{
		cout << "please enter associate name:";
		cin >> associate_name;
		cout << "please enter employee ID:";
		cin >> employee_ID;
		cin.ignore();
	}
	void sales_associate_details()
	{
		cout << "associate name:" << associate_name;
		cout << "  employee ID:" << employee_ID << endl;
	}
};
class order
{
private:
	vector <customer> customer1;
	vector <sales_associate> sales_associate1;
	vector <robotModel> robotModel1;
	vector <Arm> Arm1;
	vector <Head> Head1;
	vector <Battery> Battery1;
	vector <Locomotor> Locomotor1;
	vector <Torso> Torso1;
	string model_name;
	int model_number;
	double price;
	string track_status_;
public:
	void change_information(int quan)
	{
		robotModel1[quan].change_status("Unavailable");
	}
	void get_arm(Arm one)
	{
		Arm1.push_back(one);
	}
	void get_head(Head two)
	{
		Head1.push_back(two);
	}
	void get_battery(Battery three)
	{
		Battery1.push_back(three);
	}
	void get_locomotor(Locomotor four)
	{
		Locomotor1.push_back(four);
	}
	void get_torso(Torso five)
	{
		Torso1.push_back(five);
	}
	void get_robotModel(robotModel six)
	{
		robotModel1.push_back(six);
	}
	void get_customer_info(customer seven)
	{
		customer1.push_back(seven);
	}
	void get_associate_detail(sales_associate eight)
	{
		sales_associate1.push_back(eight);
	}
	void display_results()
	{
		for (unsigned int i = 0; i<Arm1.size(); i++)
		{
			cout << "Robot no " << i + 1 << endl;
			cout << "-----------------------------------------" << endl;
			robotModel1[i].model_details();
			cout << "-----------------------------------------" << endl;
		}
	}
	void view_details(int num1)
	{
		Arm1[num1].arm_parts_details();
		cout << "-----------------------------------------" << endl;
		Head1[num1].head_parts_details();
		cout << "-----------------------------------------" << endl;
		Battery1[num1].battery_parts_details();
		cout << "-----------------------------------------" << endl;
		Locomotor1[num1].locomotor_parts_details();
		cout << "-----------------------------------------" << endl;
		Torso1[num1].torso_parts_details();
	}
	void select_robot(int selected_robot)
	{
		customer1[selected_robot].enter_customer_details();
		sales_associate1[selected_robot].enter_associate_details();
	}
	void view_order_history(int order_history)
	{
		customer1[order_history].customer_record();
		sales_associate1[order_history].sales_associate_details();
	}
};
void CloseCB(Fl_Widget* w, void* p) {
	Fl_Window *win = (Fl_Window *)w;
	if (fl_choice("Are you sure? REALLY sure?", "Amateur!", fl_no, fl_yes) == 2)
		win->hide();
}
void CreateArmCB(Fl_Widget* w,void* p)
{
	order a;
	const char *a1 = "Please enter arm's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	string partNumber = string(c1);
	const char *d1 = "please enter arm's part description";
	const char *e1 = "0";
	const char *f1 = fl_input(d1, e1);
	string partDiscription = string(f1);
	const char *g1 = "please enter arm's cost";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double partCost = atof(i1);
	const char *j1 = "please enter arm's weight";
	const char *k1 = "0";
	const char *l1 = fl_input(j1, k1);
	double partWeight = atof(l1);
	const char *m1 = "please enter arm's power consumption";
	const char *n1 = "0";
	const char *o1 = fl_input(m1, n1);
	double partConsumed = atof(o1);
	const char *p1 = "please enter no of arms \nNow please click on Create>Robot Head to create robot's head";
	const char *q1 = "";
	const char *r1 = fl_input(p1, q1);
	int arms_quantity = atoi(r1);
	string choosePart = "Arm";
	Arm the_arm(choosePart,partNumber,partDiscription,partCost,partWeight,partConsumed,arms_quantity);
    a.get_arm(the_arm);
}
void CreateHeadCB(Fl_Widget* w, void* p)
{
	order a;
	const char *a1 = "Please enter head's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	string partNumber = string(c1);
	const char *d1 = "please enter head's part description";
	const char *e1 = "0";
	const char*f1 = fl_input(d1, e1);
	string partDiscription = string(f1);
	const char *g1 = "please enter head's cost";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double partCost = atof(i1);
	const char *j1 = "please enter head's weight \nNow please click on Create>Robot Battery to create robot's battery";
	const char *k1 = "0";
	const char *l1 = fl_input(j1, k1);
	double partWeight = atof(l1);
	string choosePart = "Head";
	Head the_head(choosePart, partNumber, partDiscription, partCost, partWeight);
	a.get_head(the_head);
}
void CreateBatteryCB(Fl_Widget* w, void* p)
{
	order a;
	const char *a1 = "Please enter battery's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	string partNumber = string(c1);
	const char *d1 = "please enter battery's part description";
	const char *e1 = "0";
	const char*f1 = fl_input(d1, e1);
	string partDiscription = string(f1);
	const char *g1 = "please enter battery's cost";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double partCost = atof(i1);
	const char *j1 = "please enter battery's weight";
	const char *k1 = "0";
	const char *l1 = fl_input(j1, k1);
	double partWeight = atof(l1);
	const char* m1 = "please enter battery's energy value";
	const char* n1 = "0";
	const char *o1 = fl_input(m1,n1);
	double energyValue = atof(o1);
	const char *p1 = "please enter battery's max power \nNow please click on Create>Robot Locomotor to create robot's locomotor";
	const char *q1 = "0";
	const char *r1 = fl_input(p1,q1);
	double partMaxPower = atof(r1);
	string choosePart = "Battery";
	Battery the_battery(choosePart, partNumber, partDiscription, partCost, partWeight, energyValue, partMaxPower);
	a.get_battery(the_battery);
}
void CreateLocomotorCB(Fl_Widget* w, void* p)
{
	order a;
	const char *a1 = "Please enter locomotor's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	string partNumber = string(c1);
	const char *d1 = "please enter locomotor's part description";
	const char *e1 = "0";
	const char*f1 = fl_input(d1, e1);
	string partDiscription = string(f1);
	const char *g1 = "please enter locomotor's cost";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double partCost = atof(i1);
	const char *j1 = "please enter locomotor's weight";
	const char *k1 = "0";
	const char *l1 = fl_input(j1, k1);
	double partWeight = atof(l1);
	const char* m1 = "please enter torso's max speed";
	const char* n1 = "0";
	const char *o1 = fl_input(m1, n1);
	double partMaxSpeed = atof(o1);
	const char *p1 = "please enter torso's power consumed \nNow please click on Create>Robot Torso to create robot's torso";
	const char *q1 = "0";
	const char *r1 = fl_input(p1, q1);
	double partConsumedPower = atof(r1);
	string choosePart = "Locomotor";
	Locomotor the_locomotor(choosePart, partNumber, partDiscription, partCost, partWeight, partMaxSpeed, partConsumedPower);
	a.get_locomotor(the_locomotor);
}
void CreateTorsoCB(Fl_Widget* w, void* p)
{
	order a;
	const char *a1 = "Please enter torso's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	string partNumber = string(c1);
	const char *d1 = "please enter torso's part description";
	const char *e1 = "0";
	const char*f1 = fl_input(d1, e1);
	string partDiscription = string(f1);
	const char *g1 = "please enter torso's cost";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double partCost = atof(i1);
	const char *j1 = "please enter torso's weight";
	const char *k1 = "0";
	const char *l1 = fl_input(j1, k1);
	double partWeight = atof(l1);
	const char* m1 = "please enter batter compartments \nNow please click on Create>Robot Model to define robot model";
	const char* n1 = "0";
	const char *o1 = fl_input(m1, n1);
	int batterySlot = atoi(o1);
	string choosePart = "Torso";
	Torso the_torso(choosePart, partNumber, partDiscription, partCost, partWeight, batterySlot);
	a.get_torso(the_torso);
}
void CreateModelCB(Fl_Widget* w, void* p) 
{
	const char *a1 = "please enter model name";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	string name_model = string(c1);
	const char *d1 = "please enter model number";
	const char *e1 = "0";
	const char*f1 = fl_input(d1, e1);
	int number_model = atoi(f1);
	const char *g1 = "please enter model price";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double price_model = atof(i1);
	robotModel robotDiscription(name_model, number_model, price_model, "currently available");
}
void AllModelCB(Fl_Widget* w, void* p)
{
	
}
Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
	{ 0 },
	{"&Create",0,0,0,FL_SUBMENU},
	{ "&Robot Arm", FL_ALT + 'a', (Fl_Callback *)CreateArmCB },
	{ "&Robot Head", FL_ALT + 'b', (Fl_Callback *)CreateHeadCB },
	{ "&Robot Battery", FL_ALT + 'c', (Fl_Callback *)CreateBatteryCB },
	{ "&Robot Locomotor", FL_ALT + 'e', (Fl_Callback *)CreateLocomotorCB },
	{ "&Robot Torso", FL_ALT + 'f', (Fl_Callback *)CreateTorsoCB },
	{ "&Robot Model", FL_ALT + 'f', (Fl_Callback *)CreateModelCB },
	{0},
	{ "&Report",0,0,0,FL_SUBMENU },
	{ "&All Robot Models", FL_ALT + 'f', (Fl_Callback *)AllModelCB },
	{0},
	{0}
};
int main() {
	//order a;
	//a.display_results();
	const int w = 640;//Fl::w();
	const int h = 480;//Fl::h();
	Fl_Window *window = new Fl_Window(w, h, "Welcome to Robbie Robot Shop");
	Fl_Box *box = new Fl_Box(0, 0, w, h);
	Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, w, 30);
	menubar->menu(menuitems);
	window->callback(CloseCB);
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	window->resizable(*box);
	window->end();
	window->show();
	return Fl::run();
}