#include <string>
#include <cctype>
#include <vector>
#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.h>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
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
	/*void arm_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Part power consumption:" << power_consumed << endl;
		cout << "number of arms:" << number_of_arms << endl;
	}*/
};
class Head : public robot_part
{
private:
	string head;
public:
	Head(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight)
		:robot_part(Robot_part_name, Part_number, Discription, Cost, Weight) {}
	/*void head_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
	}*/
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
	/*void battery_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Battery energy:" << energy << endl;
		cout << "Battery max_power:" << max_power << endl;
	}*/
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
	/*void locomotor_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "max speed:" << max_speed << endl;
		cout << "power consumed:" << consumed_power << endl;
	}*/
};
class Torso : public robot_part
{
private:
	int number_of_battery;
public:
	Torso(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight, int Number_of_battery)
		: robot_part(Robot_part_name, Part_number, Discription, Cost, Weight), number_of_battery(Number_of_battery) {}
	/*void torso_parts_details()
	{
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "number of battery:" << number_of_battery << endl;
	}*/
};
void CloseCB(Fl_Widget* w, void* p) {
	Fl_Window *win = (Fl_Window *)w;
	if (fl_choice("Are you sure? REALLY sure?", "Amateur!", fl_no, fl_yes) == 2)
		win->hide();
}
void CreateArmCB(Fl_Widget* w,void* p)
{
	const char *a1 = "Please enter arm's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	const char partNumber = *c1;
	const char *d1 = "please enter arm's part description";
	const char *e1 = "0";
	const char *f1 = fl_input(d1, e1);
	const char partDiscription = *f1;
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
	const char *p1 = "please enter no of arms";
	const char *q1 = "0";
	const char *r1 = fl_input(p1, q1);
	int arms_quantity = atoi(r1);
	string choosePart = "Arm";
	//Arm the_arm(choosePart,partNumber,partDiscription,partCost,partWeight,partConsumed,arms_quantity);
        //a.get_arm(the_arm);
}
void CreateHeadCB(Fl_Widget* w, void* p)
{
	const char *a1 = "Please enter arm's part Number";
	const char *b1 = "0";
	const char *c1 = fl_input(a1, b1);
	const char partNumber1 = *c1;
	const char *d1 = "please enter arm's part description";
	const char *e1 = "0";
	const char *f1 = fl_input(d1, e1);
	const char partDiscription1 = *f1;
	const char *g1 = "please enter arm's cost";
	const char *h1 = "0";
	const char *i1 = fl_input(g1, h1);
	double partCost2 = atof(i1);
	const char *j1 = "please enter arm's weight";
	const char *k1 = "0";
	const char *l1 = fl_input(j1, k1);
	double partWeight = atof(l1);
	const char *m1 = "please enter arm's power consumption";
	const char *n1 = "0";
	const char *o1 = fl_input(m1, n1);
	double partConsumed = atof(o1);
	const char *p1 = "please enter no of arms";
	const char *q1 = "0";
	const char *r1 = fl_input(p1, q1);
	int arms_quantity = atoi(r1);
}
Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
	{ 0 },
	{"&Create",0,0,0,FL_SUBMENU},
	{ "&Robot Arm", FL_ALT + 'a', (Fl_Callback *)CreateArmCB },
	{ "&Robot Head", FL_ALT + 'b', (Fl_Callback *)CreateHeadCB },
	{0},
	{0}
};
int main() {
	const int w = 640;//Fl::w();
	const int h = 480;//Fl::h();
	Fl_Window *window = new Fl_Window(w, h,"Welcome to Robbie Robot Shop");
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