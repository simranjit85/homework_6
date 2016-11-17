#include <cctype>
#include <vector>
#include <Windows.h>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <Fl/Fl_Multiline_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.h>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>
#include <sstream>
#include <FL/Fl_Scroll.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Shared_Image.H>
#include <Fl/Fl_JPEG_Image.H>
#include <string>
/*-----------------------------------------------------------*/
class robot_part;
class robotModel;
//class MyCanvas;
class Arm; 
class Head;
class Battery;
class Locomotor;
class Torso;
class Data_display;
class robot_pictures;
class customer;
class sales_associate;
class order;
Fl_JPEG_Image *jpg;
/*-----------------------------------------------------------*/
Fl_Window *window;
Fl_Menu_Bar *menubar;
Fl_Window *window_data;
Fl_Window *window_data_defined;
Fl_Window *window_data_image;
Fl_Window *window_customer;
Fl_Window *window_sales;
Fl_Window *window_order;
Fl_Box *box_data;
//Fl_Multiline_Output outputData;
Fl_Box *box;
//MyCanvas* canvas_widget;
robot_part* robot_part_widget;
Arm*Arm_widget;
Head* Head_widget;
Battery* Battery_widget;
Locomotor*Locomotor_widget;
Torso *Torso_widget;
Data_display*data_display_widget;
robotModel *robotModel_widget;
robot_pictures* robot_picture_widget;
customer *customer_widget;
sales_associate *sales_associate_widget;
order *order_widget;
Fl_Box *box_image;
/*-----------------------------------------------------------*/
using namespace std;
vector <string> storage_data;
vector<string> sales_storage;
vector <string> store_images_data;
void DisplayPartCB(Fl_Widget* w, void* p);
void CreatePartCB(Fl_Widget* w, void* p);
void DefineModelCB(Fl_Widget* w, void* p);
void DisplayImageCB(Fl_Widget* w, void* p);
void image_inputCB(Fl_Widget*w, void* p);
void CreateCustomerCB(Fl_Widget* w, void* p);
void CreateSalesAssociate(Fl_Widget* w, void* p);
void createOrder(Fl_Widget*w, void* p);
void getread(Fl_Widget*w, void* p);
void populate_images(Fl_Widget*w, void* p);
//void first_image(Fl_Widget* w, void* p);
string data_1="																					Detailed Robot Parts\n\n";
string data_2 = "																				Defined Models\n\n";
string data_3 = "";
string data_4 = "																				Customer Information\n\n";
string data_5 = "																				List of Sale's Associate\n\n";
string data_6 = "																				Order History\n\n";
string c_store;
const char *cc_image;
//vector<string> storage;
/*Fl_Window *dialog;
Fl_Input *rp_name;
Fl_Input *rp_part_number;
//Fl_Input *rp_type1;
Fl_Input *rp_weight;
Fl_Input *rp_cost;
Fl_Input *rp_description;
Fl_Return_Button *rp_create;
Fl_Button *rp_cancel;*/
int con_customer=0;
int con_associate=0;
class robot_part
{
private:
	/*string robot_part_name;
	string part_number;
	string discription;
	double cost;
	double weight;*/
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	Fl_Input *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Input *rp_power_consumed;
	Fl_Input *rp_no_of_arms;
	Fl_Input *rp_energy;
	Fl_Input *rp_max_power;
	Fl_Input *rp_max_speed;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
public:
	/*Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	Fl_Input *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Input *rp_power_consumed;
	Fl_Input *rp_no_of_arms;
	Fl_Input *rp_energy;
	Fl_Input *rp_max_power;
	Fl_Input *rp_max_speed;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;*/
	robot_part()
	{
		dialog = new Fl_Window(340, 470, "Robot Part");
		rp_type = new Fl_Input(120, 10, 210, 25, "Type:");
		rp_type->align(FL_ALIGN_LEFT);
		rp_name = new Fl_Input(120, 40, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_name2->value());
		//data_1 = rp_name2->value()+'\n';
		//rp_name2->readonly();
		//check = rp_name2->value();
		rp_part_number = new Fl_Input(120, 70, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_part_number2->value());
		//data_1 = data_1 + rp_part_number2->value()+'\n';
		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_weight2->value());
		//data_1 = data_1 + rp_weight2->value() + '\n';
		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_cost2->value());
		//data_1 = data_1 + rp_cost2->value() + '\n';
		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_description2->value());
		//data_1 = data_1 + rp_description2->value() + '\n';
		rp_power_consumed = new Fl_Input(120, 240, 210, 25, "Power consumed:");
		rp_power_consumed->align(FL_ALIGN_LEFT);
		rp_no_of_arms = new Fl_Input(120, 270, 210, 25, "No of arms:");
		rp_no_of_arms->align(FL_ALIGN_LEFT);
		rp_energy = new Fl_Input(120, 300, 210, 25, "Energy:");
		rp_energy->align(FL_ALIGN_LEFT);
		rp_max_power = new Fl_Input(120, 330, 210, 25, "Max power:");
		rp_max_power->align(FL_ALIGN_LEFT);
		rp_max_speed = new Fl_Input(120, 360, 210, 25, "Max speed:");
		rp_max_speed->align(FL_ALIGN_LEFT);
		rp_create = new Fl_Return_Button(145, 390, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)CreatePartCB, 0);
		/*_cancel = new Fl_Button(270, 420, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);*/
		dialog->end();
		dialog->set_non_modal();
		//data_1 = (rp_name2->value())+ (rp_part_number2->value())+ (rp_weight2->value())+ (rp_cost2->value())+ (rp_description2->value());
		/*storage.push_back(rp_name2->value());
		storage.push_back(rp_part_number2->value());
		storage.push_back(rp_weight2->value());
		storage.push_back(rp_cost2->value());
		storage.push_back(rp_description2->value());*/
	}
	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string type() 
	{ 
		string aa = "Part type:";
		return aa+rp_type->value(); 
	}
	string name() 
	{
		string bb = "Part name:";
		return bb + rp_name->value();
	}
	string part_number() 
	{ 
		string cc = "Part number:";
		return cc+rp_part_number->value(); 
	}
	string weight() 
	{ 
		string dd = "Weight:";
		return dd+rp_weight->value(); 
	}
	string cost() 
	{ 
		string ee = "Cost:";
		return ee+rp_cost->value(); 
	}
	string description() 
	{ 
		string ff = "Description:";
		return ff+rp_description->value(); 
	}
	string power_consumed()
	{
		string gg = "Power consumed:";
		return gg+rp_power_consumed->value(); 
	}
	string no_of_arms()
	{
		string hh = "No of arms:";
		return hh+rp_no_of_arms->value();
	}
	string energy()
	{
		string ii = "Energy:";
		return ii + rp_energy->value();
	}
	string max_power()
	{
		string jj = "Max power:";
		return jj + rp_max_power->value();
	}
	string max_speed()
	{
		string kk = "Max speed:";
		return kk + rp_max_speed->value();
	}
};
class robot_pictures
{
private:
	Fl_Window *dialog2;
	Fl_Input *rp_picture_name2;
	Fl_Return_Button *rp_create_picture;
	Fl_Return_Button *rp_Display_Image;
public:
	robot_pictures()
	{
	dialog2 = new Fl_Window(340, 470, "Robot images");
	rp_picture_name2 = new Fl_Input(120, 10, 210, 25, "Image name:");
	rp_picture_name2->align(FL_ALIGN_LEFT);
	rp_create_picture = new Fl_Return_Button(145, 390, 120, 25, "Create image");
	rp_create_picture->callback((Fl_Callback *)image_inputCB, 0); 
	rp_Display_Image =new Fl_Return_Button(270, 420, 60, 25, "Display Image");
	rp_Display_Image->callback((Fl_Callback *)populate_images, 0);
	dialog2->end();
	dialog2->set_non_modal();
	}
	void show()
	{ 
		dialog2->show();
	}
	void hide() 
	{ 
		dialog2->hide(); 
	}
	string picture_robot()
	{
		//string aa = "Image type:";
		return rp_picture_name2->value();
	}
};
/*
class Arm //: public robot_part
{
private:
	double power_consumed;
	int number_of_arms;
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	//Fl_Input *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;    //string check;
public:
	//string check="ginni";
	Arm(string Robot_part_name, string Part_number, string Discription, double Cost, double Weight, double power_Consumed, int Number_of_arms)
		: robot_part(Robot_part_name, Part_number, Discription, Cost, Weight), number_of_arms(Number_of_arms), power_consumed(power_Consumed) {}
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
		const char *a = robot_part_name.c_str();
		const char *b = part_number.c_str();
		const char *c = discription.c_str();
		stringstream dd;
		dd << cost;
		string ddd;
		dd >> ddd;
		const char *d = ddd.c_str();
		stringstream ee;
		ee << weight;
		string eee;
		ee >> eee;
		//const char *e = eee.c_str();
		//const char f = *a + *b + *c + *d + *e;
		stringstream ff;
		ff << power_consumed;
		string fff;
		ff >> fff;
		stringstream gg;
		gg << number_of_arms;
		string ggg;
		gg >> ggg;
		//const char *g = &f;
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Part power consumption:" << power_consumed << endl;
		cout << "number of arms:" << number_of_arms << endl;
		Fl_Window *win1 = new Fl_Window{ 640/2,480/2,"hello"};
		win1->end();
		win1->show();
		//data_1 = (Arm_widget->name()) +'\n'+(Arm_widget->part_number()) +'\n'+(Arm_widget->weight()) +'\n'+(Arm_widget->cost()) +'\n'+(Arm_widget->description());
	Arm()
	{
		dialog = new Fl_Window(340, 270, "Robot Part");
		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_name2->value());
		//data_1 = rp_name2->value()+'\n';
		//rp_name2->readonly();
		//check = rp_name2->value();
		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_part_number2->value());
		//data_1 = data_1 + rp_part_number2->value()+'\n';
		//rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
		//rp_type->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_weight2->value());
		//data_1 = data_1 + rp_weight2->value() + '\n';
		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_cost2->value());
		//data_1 = data_1 + rp_cost2->value() + '\n';
		rp_description= new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
		//storage.push_back(rp_description2->value());
		//data_1 = data_1 + rp_description2->value() + '\n';
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)CreatePartCB, 0);
		_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
		dialog->end();
		dialog->set_non_modal();
		//data_1 = (rp_name2->value())+ (rp_part_number2->value())+ (rp_weight2->value())+ (rp_cost2->value())+ (rp_description2->value());
		storage.push_back(rp_name2->value());
		storage.push_back(rp_part_number2->value());
		storage.push_back(rp_weight2->value());
		storage.push_back(rp_cost2->value());
		storage.push_back(rp_description2->value());
	}
	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
    //string name() { return check; }
	//char* Name() = { return (rp_name2->value()).c_str(); }
	string name() { 
		string nn = "robot name";
		return nn+rp_name->value(); 
	}
	string part_number() { return rp_part_number->value(); }
	//string type() { return rp_type2->value(); }
	string weight() { return rp_weight->value(); }
	string cost() { return rp_cost->value(); }
	string description() { return rp_description->value(); }
};
//string Arm::check = "checking";
class Head //: public robot_part
{
private:

	//string head;
	Fl_Window *dialog1;
	Fl_Input *rp_name1;
	Fl_Input *rp_part_number1;
	//Fl_Input *rp_type1;
	Fl_Input *rp_weight1;
	Fl_Input *rp_cost1;
	Fl_Input *rp_description1;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	//Fl_Input *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
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
		const char *a = robot_part_name.c_str();
		const char *b = part_number.c_str();
		const char *c = discription.c_str();
		stringstream dd;
		dd << cost;
		string ddd;
		dd >> ddd;
		const char *d = ddd.c_str();
		stringstream ee;
		ee << weight;
		string eee; 
		ee >> eee;
		const char *e = eee.c_str();
		Fl_Window *win2 = new Fl_Window{ 640 / 2,480 / 2,"hello" };
		win2->end();
		win2->show();
	}
	Head()
	{
		dialog = new Fl_Window(340, 270, "Robot Part");
		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);
		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);
		//rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
		//rp_type->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);
		rp_description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)CreatePartCB, 0);
		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}
	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	//string name() { return check; }
	//char* Name() = { return (rp_name2->value()).c_str(); }
	string name() { return rp_name->value(); }
	string part_number() { return rp_part_number->value(); }
	//string type() { return rp_type2->value(); }
	string weight() { return rp_weight->value(); }
	string cost() { return rp_cost->value(); }
	string description() { return rp_description->value(); }
};
class Battery //: public robot_part
{
private:
	double energy;
	double max_power;
	//string head;
	Fl_Window *dialog3;
	Fl_Input *rp_name3;
	Fl_Input *rp_part_number3;
	//Fl_Input *rp_type3;
	Fl_Input *rp_weight3;
	Fl_Input *rp_cost3;
	Fl_Input *rp_description3;
	Fl_Input *rp_energy3;
	Fl_Input *rp_max_power3;
	Fl_Return_Button *rp_create3;
	Fl_Button *rp_cancel3;
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
		const char *a = robot_part_name.c_str();
		const char *b = part_number.c_str();
		const char *c = discription.c_str();
		stringstream dd;
		dd << cost;
		string ddd;
		dd >> ddd;
		const char *d = ddd.c_str();
		stringstream ee;
		ee << weight;
		string eee;
		ee >> eee;
		//const char *e = eee.c_str();
		//const char f = *a + *b + *c + *d + *e;
		stringstream ff;
		ff << energy;
		string fff;
		ff >> fff;
		stringstream gg;
		gg << max_power;
		string ggg;
		gg >> ggg;
		//const char *g = &f;
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Part power consumption:" << power_consumed << endl;
		cout << "number of arms:" << number_of_arms << endl;
		Fl_Window *win3 = new Fl_Window{ 640 / 2,480 / 2,"hello" };
		win3->end();
		win3->show();
	}
	Battery()
	{
		dialog3 = new Fl_Window(340, 270, "Robot Part");
		rp_name3 = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name3->align(FL_ALIGN_LEFT);
		rp_part_number3 = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number3->align(FL_ALIGN_LEFT);
		//rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
		//rp_type->align(FL_ALIGN_LEFT);
		rp_weight3 = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight3->align(FL_ALIGN_LEFT);
		rp_cost3 = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost3->align(FL_ALIGN_LEFT);
		rp_description3= new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rp_description3->align(FL_ALIGN_LEFT);
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
		dialog3->end();
		dialog3->set_non_modal();
	}
	void show() { dialog3->show(); }
	void hide() { dialog3->hide(); }
};
class Locomotor //: public robot_part
{
private:
	double max_speed;
	double consumed_power;
	Fl_Window *dialog4;
	Fl_Input *rp_name4;
	Fl_Input *rp_part_number4;
	//Fl_Input *rp_type4;
	Fl_Input *rp_weight4;
	Fl_Input *rp_cost4;
	Fl_Input *rp_description4;
	Fl_Input *rp_energy4;
	Fl_Input *rp_max_power4;
	Fl_Return_Button *rp_create4;
	Fl_Button *rp_cancel4;
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
		const char *a = robot_part_name.c_str();
		const char *b = part_number.c_str();
		const char *c = discription.c_str();
		stringstream dd;
		dd << cost;
		string ddd;
		dd >> ddd;
		const char *d = ddd.c_str();
		stringstream ee;
		ee << weight;
		string eee;
		ee >> eee;
		//const char *e = eee.c_str();
		//const char f = *a + *b + *c + *d + *e;
		stringstream ff;
		ff << max_speed;
		string fff;
		ff >> fff;
		stringstream gg;
		gg << consumed_power;
		string ggg;
		gg >> ggg;
		//const char *g = &f;
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Part power consumption:" << power_consumed << endl;
		cout << "number of arms:" << number_of_arms << endl;
		Fl_Window *win4 = new Fl_Window{ 640 / 2,480 / 2,"hello" };
		win4->end();
		win4->show();
	}
	Locomotor()
	{
		dialog4 = new Fl_Window(340, 270, "Robot Part");
		rp_name4 = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name4->align(FL_ALIGN_LEFT);
		rp_part_number4 = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number4->align(FL_ALIGN_LEFT);
		//rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
		//rp_type->align(FL_ALIGN_LEFT);
		rp_weight4 = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight4->align(FL_ALIGN_LEFT);
		rp_cost4 = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost4->align(FL_ALIGN_LEFT);
		rp_description4 = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rp_description4->align(FL_ALIGN_LEFT);
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
		dialog4->end();
		dialog4->set_non_modal();
	}
	void show() { dialog4->show(); }
	void hide() { dialog4->hide(); }
};
class Torso// : public robot_part
{
private:
	//int number_of_battery;
	Fl_Window *dialog5;
	Fl_Input *rp_name5;
	Fl_Input *rp_part_number5;
	//Fl_Input *rp_type5;
	Fl_Input *rp_weight5;
	Fl_Input *rp_cost5;
	Fl_Input *rp_description5;
	Fl_Input *rp_energy5;
	Fl_Input *rp_max_power5;
	Fl_Return_Button *rp_create5;
	Fl_Button *rp_cancel5;
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
		const char *a = robot_part_name.c_str();
		const char *b = part_number.c_str();
		const char *c = discription.c_str();
		stringstream dd;
		dd << cost;
		string ddd;
		dd >> ddd;
		const char *d = ddd.c_str();
		stringstream ee;
		ee << weight;
		string eee;
		ee >> eee;
		//const char *e = eee.c_str();
		//const char f = *a + *b + *c + *d + *e;
		stringstream ff;
		ff << number_of_battery;
		string fff;
		ff >> fff;
		//const char *g = &f;
		cout << "Part name:" << robot_part_name << endl;
		cout << "Part number:" << part_number << endl;
		cout << "Part description:" << discription << endl;
		cout << "Part cost:" << cost << endl;
		cout << "Part weight:" << weight << endl;
		cout << "Part power consumption:" << power_consumed << endl;
		cout << "number of arms:" << number_of_arms << endl;
		Fl_Window *win5 = new Fl_Window{ 640 / 2,480 / 2,"hello" };
		win5->end();
		win5->show();
	}
	Torso()
	{
		dialog5 = new Fl_Window(340, 270, "Robot Part");
		rp_name5 = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name5->align(FL_ALIGN_LEFT);
		rp_part_number5 = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number5->align(FL_ALIGN_LEFT);
		//rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
		//rp_type->align(FL_ALIGN_LEFT);
		rp_weight5 = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight5->align(FL_ALIGN_LEFT);
		rp_cost5 = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost5->align(FL_ALIGN_LEFT);
		rp_description5 = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rp_description5->align(FL_ALIGN_LEFT);
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
		dialog5->end();
		dialog5->set_non_modal();
	}
	void show() { dialog5->show(); }
	void hide() { dialog5->hide(); }
};
class Data_display
{
private:
	Fl_Window *show_data;
public:
	Data_display()
	{

	}
};
*/
class robotModel
{
//private:
	/*string name_model;
	int number_model;
	double price_model;
	string track_status;
public:

	/*robotModel(string Name_model, int Number_model, double Price_model, string Track_status)
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
		const char *a = name_model.c_str();
		stringstream dd;
		dd << number_model;
		string ddd;
		dd >> ddd;
		const char *d = ddd.c_str();
		stringstream ee;
		ee << price_model;
		string eee;
		ee >> eee;
		const char *b = track_status.c_str();
		Fl_Window *win6 = new Fl_Window{ 640 / 2,480 / 2,"hello" };
		win6->end();
		win6->show();
	}*/
private:
	Fl_Window *dialog1;
	Fl_Input *rp_model_name;
	Fl_Input *rp_model_number;
	Fl_Input *rp_model_price;
	Fl_Return_Button *rp_create1;
public:
	/*string name_model;
	int number_model;
	double price_model;
	string track_status;*/
	robotModel()
	{
		dialog1 = new Fl_Window(340, 270, "Robot Part");
		rp_model_name = new Fl_Input(120, 10, 210, 25, "Type:");
		rp_model_name->align(FL_ALIGN_LEFT);
		rp_model_number = new Fl_Input(120, 40, 210, 25, "Name:");
		rp_model_number->align(FL_ALIGN_LEFT);
		rp_model_price = new Fl_Input(120, 70, 210, 25, "Part Number:");
		rp_model_price->align(FL_ALIGN_LEFT);
		rp_create1 = new  Fl_Return_Button(120, 100, 120, 25, "Create");
		rp_create1->callback((Fl_Callback *)DefineModelCB, 0);
		dialog1->end();
		dialog1->set_non_modal();
	}
	void show() { dialog1->show(); }
	void hide() { dialog1->hide(); }
	string model_name() 
	{ 
		string aa = "Model name:";
		return aa+rp_model_name->value(); 
	}
	string model_number() 
	{ 
		string bb = "Model number:";
		return bb+rp_model_number->value(); 
	}
	string model_price()
	{ 
		string cc = "Model price";
		return cc+rp_model_price->value(); 
	}

};

class customer
{
//private:
	/*string customer_name;
	string customer_number;
	double wallet;*/
//public:
	/*customer(string Customer_name, string Customer_number, double Wallet)
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
	}*/
private:
	Fl_Window *dialog3;
	Fl_Input *rp_customer_name;
	Fl_Input *rp_customer_number;
	Fl_Input * rp_wallet;
	Fl_Return_Button *rp_create3;
public:
	customer()
	{
		dialog3 = new Fl_Window(340, 270, "Robot Part");
		rp_customer_name = new Fl_Input(120, 10, 210, 25, "Customer name:");
		rp_customer_name->align(FL_ALIGN_LEFT);
		rp_customer_number = new Fl_Input(120, 40, 210, 25, "Customer number:");
		rp_customer_number->align(FL_ALIGN_LEFT);
		rp_wallet = new Fl_Input(120, 70, 210, 25, "Customer wallet:");
		rp_wallet->align(FL_ALIGN_LEFT);
		rp_create3 = new  Fl_Return_Button(120, 100, 120, 25, "Create");
		rp_create3->callback((Fl_Callback *)CreateCustomerCB, 0);
		dialog3->end();
		dialog3->set_non_modal();
	}
	void show() { dialog3->show(); }
	void hide() { dialog3->hide(); }
	string customer_name()
	{
		string aa = "Customer name:";
		return aa + rp_customer_name->value();
	}
	string customer_number()
	{
		string bb = "Customer number:";
		return bb + rp_customer_number->value();
	}
	string wallet()
	{
		string cc = "Wallet";
		return cc + rp_wallet->value();
	}
};

class sales_associate
{
private:
	/*string associate_name;
	int employee_ID;*/
	Fl_Window *dialog5;
	Fl_Input *rp_associate_name;
	Fl_Input *rp_employee_ID;
	Fl_Return_Button *rp_create4;
	//Fl_Return_Button *rp_create5;
public:
	sales_associate()
	{
		dialog5 = new Fl_Window(340, 270, "Robot Part");
		rp_associate_name = new Fl_Input(120, 10, 210, 25, "Associate name:");
		rp_associate_name->align(FL_ALIGN_LEFT);
		rp_employee_ID = new Fl_Input(120, 40, 210, 25, "Employee ID Number:");
		rp_employee_ID->align(FL_ALIGN_LEFT);
		rp_create4 = new  Fl_Return_Button(120, 100, 120, 25, "Create");
		rp_create4->callback((Fl_Callback *)CreateSalesAssociate, 0);
		dialog5->end();
		dialog5->set_non_modal();
	}
	void show() { dialog5->show(); }
	void hide() { dialog5->hide(); }
	string associate_name()
	{
		string aa = "Associate name:";
		return aa + rp_associate_name->value();
	}
	string employee_number()
	{
		string bb = "Employee ID:";
		return bb + rp_employee_ID->value();
	}
	/*sales_associate(string Associate_name, int Employee_ID)
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
	}*/
};

class order
{
private:
	Fl_Window *dialog6;
	Fl_Input *rp_associate_number;
	Fl_Input *rp_customer_number;
	Fl_Return_Button *rp_create6;
	Fl_Return_Button *rp_create7;
public:
	order()
	{
		dialog6 = new Fl_Window(340, 270, "Robot Part");
		rp_associate_number = new Fl_Input(120, 10, 210, 25, "Associate Number:");
		rp_associate_number->align(FL_ALIGN_LEFT);
		rp_customer_number = new Fl_Input(120, 40, 210, 25, "Customer Number:");
		rp_customer_number->align(FL_ALIGN_LEFT);
		rp_create6 = new  Fl_Return_Button(120, 100, 120, 25, "Create");
		rp_create6->callback((Fl_Callback *)createOrder, 0);
		rp_create7 = new  Fl_Return_Button(120, 150, 120, 25, "Create Order");
		rp_create7->callback((Fl_Callback *)getread, 0);
		//void getread(Fl_Widget*w, void* p)
		dialog6->end();
		dialog6->set_non_modal();
	}
	void show() { dialog6->show(); }
	void hide() { dialog6->hide(); }
	string associate_number()
	{
		//string aa = "Associate Number:";
		return rp_associate_number->value();
	}
	string customer_number()
	{
		//string bb = "Customer Number:";
		return rp_customer_number->value();
	}
};

/*
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
};*/
//order a;
class MyCanvas : public Fl_Scroll {
public:
	MyCanvas(int X, int Y, int W, int H, const char*L = 0) : Fl_Scroll(X, Y, W, H, L) {
	}
	void draw() {
		// DRAW BG
		//fl_color(color());
		//fl_rectf(x(), y(), w(), h());
		// DRAW 'X' OVER BG
		//   Do your graphics here..
		//
		int x1 = x(), y1 = y();               // Fl_Scroll works by changing our widget's x() and y(),
		//int x2 = x() + w() - 1, y2 = y() + h() - 1;   // so take these into account for our drawing coordinates  
	}
};
void CloseCB(Fl_Widget* w, void* p) {
	Fl_Window *window = (Fl_Window *)w;
	if (fl_choice("Are you sure? REALLY sure?", "Amateur!", fl_no, fl_yes) == 2)
		window->hide();
	//if (ask("Do you really want to exit?"))
		//((window*) Fl_Box)->hide();
}
void CreateArmCB(Fl_Widget* w, void* p)
{
	//Arm_widget->show();
	/*const char *a1 = "Please enter arm's part Number";
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
	Arm the_arm(choosePart, partNumber, partDiscription, partCost, partWeight, partConsumed, arms_quantity);
	a.get_arm(the_arm);*/
}
void CreateHeadCB(Fl_Widget* w, void* p)
{
	//Head_widget->show();
	/*const char *a1 = "Please enter head's part Number";
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
	a.get_head(the_head);*/
}
void CreateBatteryCB(Fl_Widget* w, void* p)
{
	//Battery_widget->show();
	/*const char *a1 = "Please enter battery's part Number";
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
	const char *o1 = fl_input(m1, n1);
	double energyValue = atof(o1);
	const char *p1 = "please enter battery's max power \nNow please click on Create>Robot Locomotor to create robot's locomotor";
	const char *q1 = "0";
	const char *r1 = fl_input(p1, q1);
	double partMaxPower = atof(r1);
	string choosePart = "Battery";
	Battery the_battery(choosePart, partNumber, partDiscription, partCost, partWeight, energyValue, partMaxPower);
	a.get_battery(the_battery);*/
}
void CreateLocomotorCB(Fl_Widget* w, void* p)
{
	//Locomotor_widget->show();
	/*const char *a1 = "Please enter locomotor's part Number";
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
	a.get_locomotor(the_locomotor);*/
}
void CreateTorsoCB(Fl_Widget* w, void* p)
{
	//Torso_widget->show();
	/*const char *a1 = "Please enter torso's part Number";
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
	a.get_torso(the_torso);*/
}
/*void CreateModelCB(Fl_Widget* w, void* p)
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
	a.display_results();
}*/
void showRobotPartCB(Fl_Widget* w, void* p)
{
	robot_part_widget->show();
}
void showDefinedRobotPartCB(Fl_Widget* w, void* p)
{
	robotModel_widget->show();
}
void ShowImage(Fl_Widget* w, void* p)
{
	robot_picture_widget->show();
}
void customer_history(Fl_Widget*w, void* p)
{
	customer_widget->show();
}
void sales_info(Fl_Widget*w, void* p)
{
	sales_associate_widget->show();
}
void order_infoCB()
{
	order_widget->show();
}
void createOrder(Fl_Widget*w, void* p)
{
	string a = order_widget->associate_number();
	const char*Con_associate = a.c_str();
	con_associate = atoi(Con_associate);
	string b = order_widget->customer_number();
	const char*Con_customer = b.c_str();
	con_customer = atoi(Con_customer);
	//data_6 = data_6+ "Order for" + storage_data[con_customer]+"Created by"+sales_storage[con_associate]+'\n';
}
void getread(Fl_Widget*w, void* p)
{
	data_6 = data_6 + "Order for" + storage_data[con_customer-1 ] + "Created by" + sales_storage[con_associate -1] + '\n';
}
void CreatePartCB(Fl_Widget* w, void* p)
{
	data_1 = data_1 + robot_part_widget->type() +'\n'+(robot_part_widget->name()) + '\n' + (robot_part_widget->part_number()) + '\n' + 
		(robot_part_widget->weight()) + '\n' + (robot_part_widget->cost()) + '\n' + (robot_part_widget->description())+'\n'+ (robot_part_widget->power_consumed())+'\n'+ 
		(robot_part_widget->no_of_arms())+'\n'+ (robot_part_widget->energy())+ '\n'+(robot_part_widget->max_power())+ '\n'+(robot_part_widget->max_speed())+'\n';
}
void DefineModelCB(Fl_Widget* w, void* p)
{
	data_2 = data_2 + robotModel_widget->model_name() + '\n' + robotModel_widget->model_number() + '\n' + robotModel_widget->model_price() + '\n';
}
void image_inputCB(Fl_Widget*w, void* p)
{
	//data_3 = robot_picture_widget->picture_robot();
	store_images_data.push_back(robot_picture_widget->picture_robot());
}
void populate_images(Fl_Widget*w, void* p)
{
	//for (unsigned int i = 0; i < store_images_data.size(); i++)
	////{
	int a = Fl::w();
	int h = Fl::h();
	c_store = store_images_data.back();
	cc_image = c_store.c_str();
	store_images_data.pop_back();
			Fl_Window *window_data_image1 = new Fl_Window(a, h, "demo");
			//window_data_image = new Fl_Window(a, h, "demo");
			Fl_Box *box_image1 = new Fl_Box(0, 0, a-5, h-5);
			// Load jpeg image into memory and attach to the box
			Fl_JPEG_Image *jpg1 = new Fl_JPEG_Image(cc_image);
			box_image1->image(*jpg1);
			//box->show();
			//Fl_Scroll *scroll9 = new Fl_Scroll(0, 0, a * 100, h * 100, "hello");
			window_data_image1->resizable(*box_image1);
			//robot_picture_widget->hide();
			window_data_image1->end();
			window_data_image1->show();
}
/*void first_image(Fl_Widget* w, void* p)
{
	c_store = store_images_data.back();
	//cout << c << endl;
	cc_image = c_store.c_str();
	//cout << cc_image << endl;
	store_images_data.pop_back();
	//cout << cc_image << endl;
}*/
void CreateCustomerCB(Fl_Widget* w, void* p)
{
	data_4 = data_4 +'\n'+ customer_widget->customer_name()+'\n'+customer_widget->customer_number()+'\n'+customer_widget->wallet()+'\n';
	storage_data.push_back(customer_widget->customer_name() + " "+customer_widget->customer_number() + " "+ customer_widget->wallet());
}
void CreateSalesAssociate(Fl_Widget* w, void* p)
{
	data_5 = data_5 + '\n' + sales_associate_widget->associate_name() + '\n'+sales_associate_widget->employee_number()+'\n';
	sales_storage.push_back(sales_associate_widget->associate_name() + " " + sales_associate_widget->employee_number());
}
/*void DisplayImageCB(Fl_Widget* w, void* p)
{
	int a = Fl::w();
	int h = Fl::h();
	//int border = 10;
	//fl_register_images();
	window_data_image = new Fl_Window(a , h, "demo");
	Fl_Return_Button *rp_show_image;
	rp_show_image = new  Fl_Return_Button(5, 5, 120, 25, "Create");
	rp_show_image->callback((Fl_Callback *)populate_images, 0);
	//const char * Data_3 = (data_3.c_str()); 
	//const char * Data_3 = (cc_image);
	//Fl_Box *box_image = new Fl_Box(0, 0, a-5, h-5);
	// Load jpeg image into memory and attach to the box
	//jpg = new Fl_JPEG_Image(cc_image);
	//box_image->image(*jpg);
	//Fl_Scroll *scroll9 = new Fl_Scroll(0, 0, a * 100, h * 100, "hello");
	//window_data_image->resizable(*box_image);
	robot_picture_widget->hide();
	window_data_image->end();
	window_data_image->show();
}*/
void DisplayOrderCB(Fl_Widget* w, void* p)
{
	int a = Fl::w();
	int h = Fl::h();
	window_order = new Fl_Window(a * 100, h * 100, "demo");
	const char * Data_6 = (data_6.c_str());
	Fl_Scroll *scroll4= new Fl_Scroll(0, 0, a * 100, h * 100, "hello");
	Fl_Multiline_Output *outputData6 = new Fl_Multiline_Output(0, 0, a * 100, h * 100);
	outputData6->value(Data_6);
	window_order->resizable(*outputData6);
	order_widget->hide();
	window_order->end();
	window_order->show();
}
void DisplayModelCB(Fl_Widget* w, void* p)
{
	int a = Fl::w();
	int h = Fl::h();
	window_data_defined = new Fl_Window(a * 100, h * 100, "demo"); 
	const char * Data_2 = (data_2.c_str());
	Fl_Scroll *scroll2 = new Fl_Scroll(0, 0, a * 100, h * 100, "hello");
	Fl_Multiline_Output *outputData2 = new Fl_Multiline_Output(0, 0, a * 100, h * 100);
	outputData2->value(Data_2);
	window_data_defined->resizable(*outputData2);
	robotModel_widget->hide();
	window_data_defined->end();
	window_data_defined->show();
}
void DisplaySalesCB(Fl_Widget* w, void* p)
{
	int a = Fl::w();
	int h = Fl::h();
	window_sales = new Fl_Window(a * 100, h * 100, "demo");
	const char * Data_5= (data_5.c_str());
	Fl_Scroll *scroll3 = new Fl_Scroll(0, 0, a * 100, h * 100, "hello");
	Fl_Multiline_Output *outputData5 = new Fl_Multiline_Output(0, 0, a * 100, h * 100);
	outputData5->value(Data_5);
	window_sales->resizable(*outputData5);
	sales_associate_widget->hide();
	window_sales->end();
	window_sales->show();
}
void DisplayCustomerInfoCB(Fl_Widget* w, void* p)
{

	int a = Fl::w();
	int h = Fl::h();
	window_customer = new Fl_Window(a * 100, h * 100, "demo");
	const char * Data_4 = (data_4.c_str());
	Fl_Scroll *scroll3 = new Fl_Scroll(0, 0, a * 100, h * 100, "hello");
	Fl_Multiline_Output *outputData4 = new Fl_Multiline_Output(0, 0, a * 100, h * 100);
	outputData4->value(Data_4);
	window_customer->resizable(*outputData4);
	customer_widget->hide();
	window_customer->end();
	window_customer->show();
}
void DisplayPartCB(Fl_Widget* w, void* p)
{
		int a = Fl::w();
		int h = Fl::h();
		window_data = new Fl_Window(a*100, h*100,"demo");
		//string zz = "hello";
		//const char *z = "dear;";//zz.c_str();
		//cout << z << endl;
		//data_1 = (Arm_widget->name()) +'\n'+(Arm_widget->part_number()) +'\n'+(Arm_widget->weight()) +'\n'+(Arm_widget->cost()) +'\n'+(Arm_widget->description());
		/*storage.push_back(Arm_widget->name());
		storage.push_back(Arm_widget->part_number());
		storage.push_back(Arm_widget->weight());
		storage.push_back(Arm_widget->cost());
		storage.push_back(Arm_widget->description());
		for (unsigned int i = 0; i < storage.size(); i++)
		{
			data_1 = data_1+storage[i];
			cout << data_1 << endl;
		}*/
		const char * Data_1 = (data_1.c_str());
		//box_data = new Fl_Box(0, 0, a, h, z /*(Arm_widget->name()).c_str()*/);
		//canvas_widget->draw();
		Fl_Scroll *scroll = new Fl_Scroll(0, 0, a*100, h*100, "hello");
		//scroll->resize(0, 0, a, h);
		//scroll->end();
		//MyCanvas*scroll = new MyCanvas(0,0,a,h," ");
		Fl_Multiline_Output *outputData =new Fl_Multiline_Output(0,0,a*100,h*100);
		//MyCanvas*scroll = new MyCanvas(0, 0, a, h, " ");
		//outputData->value((Arm_widget->name()).c_str());
		outputData->value(Data_1);
		/*box_data->box(FL_UP_BOX);
		box_data->labelsize(36);
		box_data->labelfont(FL_BOLD + FL_ITALIC);
		box_data->labeltype(FL_SHADOW_LABEL);*/
		//Arm_widget->hide();
		//Arm_widget->clear();
		window_data->resizable(*outputData);
		robot_part_widget->hide();
		window_data->end();
		window_data->show();
	/*cout << "### Creating robot part" << endl;
	cout << "Name : " << Arm_widget->name() << endl;
	cout << "Part # : " << Arm_widget->part_number() << endl;
	//cout << "Type : " << Arm_widget->type() << endl;
	cout << "Weight : " << Arm_widget->weight() << endl;
	cout << "Cost : " << Arm_widget->cost() << endl;
	cout << "Descript: " << Arm_widget->description() << endl;
	Arm_widget->hide();*/
}
Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
	{ 0 },
	{ "&Create",0,0,0,FL_SUBMENU },
	{ "&Create Robot Part", FL_ALT + 'a', (Fl_Callback *)showRobotPartCB },
	{ "&Display Robot Part", FL_ALT + 'h', (Fl_Callback *)DisplayPartCB },
	{ "&Create Robot Model", FL_ALT + 'b', (Fl_Callback *)showDefinedRobotPartCB},
	{ "&Display Robot Model", FL_ALT + 'f', (Fl_Callback *)DisplayModelCB },
	{ "&Create Image", FL_ALT + 'f', (Fl_Callback *)ShowImage },
	//{ "&Display Image", FL_ALT + 'c', (Fl_Callback *)DisplayImageCB },
	{ "&Create Customer", FL_ALT + 'e', (Fl_Callback *)customer_history },
	{ "&Display Customer", FL_ALT + 'e', (Fl_Callback *)DisplayCustomerInfoCB },
	{ "&Create Sales Associate", FL_ALT + 'e', (Fl_Callback *)sales_info },
	{ "&Display sales Associate", FL_ALT + 'e', (Fl_Callback *)DisplaySalesCB },
	{ "&Create Order", FL_ALT + 'e', (Fl_Callback *)order_infoCB },
	{ "&Display Order", FL_ALT + 'e', (Fl_Callback *)DisplayOrderCB },
	{ 0 },
	{ "&Report",0,0,0,FL_SUBMENU },
	//{ "&All R", FL_ALT + 'h', (Fl_Callback *)DisplayArmCB },
	{ 0 },
	{ 0 }
};
int main() {
	const int w = 640;//Fl::w();
	const int h = 480;//Fl::h();
	robot_part_widget = new robot_part{};
	robotModel_widget = new robotModel{};
	robot_picture_widget = new robot_pictures{};
	customer_widget = new customer{};
	sales_associate_widget = new sales_associate{};
	order_widget = new order{};
	//canvas_widget = new MyCanvas(0, 0, w + 100, h + 100);
	/*Arm_widget = new Arm{};
	Head_widget = new Head{};
	Battery_widget = new Battery{};
	Locomotor_widget = new Locomotor{};
	Torso_widget = new Torso{};*/

	window = new Fl_Window(w, h, "Welcome to Robbie Robot Shop");
	//scroll.end();
	window->color(FL_WHITE);
	menubar = new Fl_Menu_Bar(0, 0, w, 30);
	menubar->menu(menuitems);
	box = new Fl_Box(0, 0, w, h);
	window->callback(CloseCB,box);
	window->resizable(*box);
	window->end();
	window->show();
	return Fl::run();
}