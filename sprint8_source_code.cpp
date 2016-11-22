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
int count_ = 0;
int robot_count = 1;
int count_robot_nodel = 1;
int count_customer = 1;
int count_associate = 1;
int order_count = 1;
/*-----------------------------------------------------------*/
Fl_Window *window;
Fl_Menu_Bar *menubar;
Fl_Window *window_data;
Fl_Window *window_data_defined;
Fl_Window *window_data_image;
Fl_Window *window_customer;
Fl_Window *window_sales;
Fl_Window *window_order;
Fl_Window *window_help;
Fl_Box *box_data;
Fl_Box *box;
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
vector <string> model_storage;
void DisplayPartCB(Fl_Widget* w, void* p);
void CreatePartCB(Fl_Widget* w, void* p);
void DefineModelCB(Fl_Widget* w, void* p);
void image_inputCB(Fl_Widget*w, void* p);
void CreateCustomerCB(Fl_Widget* w, void* p);
void CreateSalesAssociate(Fl_Widget* w, void* p);
void createOrder(Fl_Widget*w, void* p);
//void getread(Fl_Widget*w, void* p);
void populate_images(Fl_Widget*w, void* p);
string help_tab;
string data_1="																					Detailed Robot Parts\n\n------------------------------------------------------\n";
string data_2 = "																				Defined Models\n\n------------------------------------------------------\n";
string data_3 = "";
string data_4 = "																				Customer Information\n\n------------------------------------------------------\n";
string data_5 = "																				List of Sale's Associate\n\n------------------------------------------------------\n";
string data_6 = "																				Order History\n\n------------------------------------------------------\n";
string c_store;
const char *cc_image;
int con_customer=0;
int con_associate=0;
int con_model = 0;
class robot_part
{
private:
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
public:
	robot_part()
	{
		dialog = new Fl_Window(340, 440, "Robot Part");
		rp_type = new Fl_Input(120, 10, 210, 25, "Type:");
		rp_type->align(FL_ALIGN_LEFT);
		rp_name = new Fl_Input(120, 40, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);
		rp_part_number = new Fl_Input(120, 70, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);
		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
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
		rp_create = new Fl_Return_Button(200, 390, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)CreatePartCB, 0);
		dialog->end();
		dialog->set_non_modal();
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
	dialog2 = new Fl_Window(340, 90, "Robot images");
	rp_picture_name2 = new Fl_Input(120, 10, 210, 25, "Image name:");
	rp_picture_name2->align(FL_ALIGN_LEFT);
	rp_create_picture = new Fl_Return_Button(70, 40, 120, 25, "Create image");
	rp_create_picture->callback((Fl_Callback *)image_inputCB, 0); 
	rp_Display_Image =new Fl_Return_Button(210, 40, 120, 25, "Display Image");
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
		return rp_picture_name2->value();
	}
};

class robotModel
{
private:
	Fl_Window *dialog1;
	Fl_Input *rp_model_name;
	Fl_Input *rp_model_number;
	Fl_Input *rp_model_price;
	Fl_Return_Button *rp_create1;
public:
	robotModel()
	{
		dialog1 = new Fl_Window(340, 150, "Robot Model");
		rp_model_name = new Fl_Input(120, 10, 210, 25, "Robot Name:");
		rp_model_name->align(FL_ALIGN_LEFT);
		rp_model_number = new Fl_Input(120, 40, 210, 25, "Robot Number:");
		rp_model_number->align(FL_ALIGN_LEFT);
		rp_model_price = new Fl_Input(120, 70, 210, 25, "Robot Price:");
		rp_model_price->align(FL_ALIGN_LEFT);
		rp_create1 = new  Fl_Return_Button(200, 100, 120, 25, "Create");
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
private:
	Fl_Window *dialog3;
	Fl_Input *rp_customer_name;
	Fl_Input *rp_customer_number;
	Fl_Input * rp_wallet;
	Fl_Return_Button *rp_create3;
public:
	customer()
	{
		dialog3 = new Fl_Window(340, 150, "Create Customer");
		rp_customer_name = new Fl_Input(120, 10, 210, 25, "Customer name:");
		rp_customer_name->align(FL_ALIGN_LEFT);
		rp_customer_number = new Fl_Input(120, 40, 210, 25, "Customer number:");
		rp_customer_number->align(FL_ALIGN_LEFT);
		rp_wallet = new Fl_Input(120, 70, 210, 25, "Customer wallet:");
		rp_wallet->align(FL_ALIGN_LEFT);
		rp_create3 = new  Fl_Return_Button(200, 100, 120, 25, "Create");
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
		string cc = "Wallet:";
		return cc + rp_wallet->value();
	}
};

class sales_associate
{
private:
	Fl_Window *dialog5;
	Fl_Input *rp_associate_name;
	Fl_Input *rp_employee_ID;
	Fl_Return_Button *rp_create4;
public:
	sales_associate()
	{
		dialog5 = new Fl_Window(370, 130, "Create Sale's Associate");
		rp_associate_name = new Fl_Input(140, 10, 210, 25, "Associate name:");
		rp_associate_name->align(FL_ALIGN_LEFT);
		rp_employee_ID = new Fl_Input(140, 40, 210, 25, "Employee ID Number:");
		rp_employee_ID->align(FL_ALIGN_LEFT);
		rp_create4 = new  Fl_Return_Button(220, 80, 120, 25, "Create");
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
};

class order
{
private:
	Fl_Window *dialog6;
	Fl_Input *rp_associate_number;
	Fl_Input *rp_customer_number;
	Fl_Input *rp_model_number;
	Fl_Input *rp_orderDate;
	Fl_Return_Button *rp_create6;
	Fl_Return_Button *rp_create7;
public:
	order()
	{
		dialog6 = new Fl_Window(340, 180, "Create Order");
		rp_associate_number = new Fl_Input(120, 10, 210, 25, "Associate Number:");
		rp_associate_number->align(FL_ALIGN_LEFT);
		rp_customer_number = new Fl_Input(120, 40, 210, 25, "Customer Number:");
		rp_customer_number->align(FL_ALIGN_LEFT);
		rp_model_number = new Fl_Input(120, 70, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);
		rp_orderDate = new Fl_Input(120, 100, 210, 25, "Order Date:");
		rp_orderDate->align(FL_ALIGN_LEFT);
		rp_create6 = new  Fl_Return_Button(200, 140, 120, 25, "Create");
		rp_create6->callback((Fl_Callback *)createOrder, 0);
		dialog6->end();
		dialog6->set_non_modal();
	}
	void show() { dialog6->show(); }
	void hide() { dialog6->hide(); }
	string associate_number()
	{
		return rp_associate_number->value();
	}
	string customer_number()
	{
		return rp_customer_number->value();
	}
	string model_number()
	{
		return rp_model_number->value();
	}
	string order_date()
	{
		return rp_orderDate->value();
	}
};
void CloseCB(Fl_Widget* w, void* p) {
	Fl_Window *window = (Fl_Window *)w;
	if (fl_choice("Are you sure? REALLY sure?", "Amateur!", fl_no, fl_yes) == 2)
		window->hide();
}
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
	stringstream ss;
	string test;
	ss << order_count;
	test = ss.str();
	string a = order_widget->associate_number();
	const char*Con_associate = a.c_str();
	con_associate = atoi(Con_associate);
	string b = order_widget->customer_number();
	const char*Con_customer = b.c_str();
	con_customer = atoi(Con_customer);
	string c = order_widget->model_number();
	const char*Con_model = a.c_str();
	con_associate = atoi(Con_model);
	data_6 = data_6 + "Order No:" + test + '\n' + "------------------------------------------------------\n" +"Order for " + "(" + storage_data[con_customer - 1] + ")" + " created by " + "(" + sales_storage[con_associate - 1] + ")" + " for " + "(" + model_storage[con_associate - 1] + ")" + " on "+ "("+order_widget->order_date()+")"+'\n'+ "------------------------------------------------------\n";
	order_count++;
}
void CreatePartCB(Fl_Widget* w, void* p)
{
	if (count_ % 5 == 0)
	{
		stringstream ss;
		string test;
		ss << robot_count;
		test=ss.str();
	data_1 = data_1 + "				Robot Number:" + test+ '\n'+ "------------------------------------------------------\n" +robot_part_widget->type() + '\n' + (robot_part_widget->name()) + '\n' + (robot_part_widget->part_number()) + '\n' +
		(robot_part_widget->weight()) + '\n' + (robot_part_widget->cost()) + '\n' + (robot_part_widget->description()) + '\n' + (robot_part_widget->power_consumed()) + '\n' +
		(robot_part_widget->no_of_arms()) + '\n' + (robot_part_widget->energy()) + '\n' + (robot_part_widget->max_power()) + '\n' + (robot_part_widget->max_speed()) + '\n' +
		"------------------------------------------------------\n";
	robot_count++;
	}
	else
	{
		data_1 = data_1 + robot_part_widget->type() + '\n' + (robot_part_widget->name()) + '\n' + (robot_part_widget->part_number()) + '\n' +
			(robot_part_widget->weight()) + '\n' + (robot_part_widget->cost()) + '\n' + (robot_part_widget->description()) + '\n' + (robot_part_widget->power_consumed()) + '\n' +
			(robot_part_widget->no_of_arms()) + '\n' + (robot_part_widget->energy()) + '\n' + (robot_part_widget->max_power()) + '\n' + (robot_part_widget->max_speed()) + '\n' +
			"------------------------------------------------------\n";
	}
	count_ = count_ + 1;
}
void DefineModelCB(Fl_Widget* w, void* p)
{
	stringstream ss;
	string test;
	ss << count_robot_nodel;
	test = ss.str();
	data_2 = data_2 + "Robot Model No:"+test+ '\n'+"------------------------------------------------------\n" +robotModel_widget->model_name() + '\n' + robotModel_widget->model_number() + '\n' + robotModel_widget->model_price() + '\n'+ "------------------------------------------------------\n";
	model_storage.push_back(robotModel_widget->model_name() + "," + robotModel_widget->model_number() + "," + robotModel_widget->model_price());
	count_robot_nodel++;
}
void HelpCB(Fl_Widget* w, void* p)
{
	help_tab = "Quick Help\n\nTo creat robot parts click on Create>Create Robot Part\nTo creat robot model click on Create>Create Robot Model\nTo creat and display images click on Create>Create and Display Image\n To creat customer click on Create>Create Customer\nTo creat sale's associate click on Create>Create Sale's Associate\nTo creat order click on Create>Create Order\nTo display robot parts click on View>Display Robot Part\nTo display robot models click on View>Display Robot Model\nTo display customer click on View>Display Customer\nTo display sale's associate click on View>Display Sale's Associate\nTo display orders click on View>Display Order\n";
	int a = Fl::w();
	int h = Fl::h();
	window_help = new Fl_Window(a/2, h/2 , "demo");
	const char * Data_12 = (help_tab.c_str());
	Fl_Box *box_1 = new Fl_Box(0,0,a/2,h/2,Data_12);
	cout << "help" << endl;
	window_help->resizable(*box_1);
	window_help->end();
	window_help->show();
}
void image_inputCB(Fl_Widget*w, void* p)
{
	store_images_data.push_back(robot_picture_widget->picture_robot());
}
void populate_images(Fl_Widget*w, void* p)
{
	int a = Fl::w();
	int h = Fl::h();
	c_store = store_images_data.back();
	cc_image = c_store.c_str();
	store_images_data.pop_back();
			Fl_Window *window_data_image1 = new Fl_Window(a, h, "demo");
			Fl_Box *box_image1 = new Fl_Box(0, 0, a-5, h-5);
			Fl_JPEG_Image *jpg1 = new Fl_JPEG_Image(cc_image);
			box_image1->image(*jpg1);
			window_data_image1->resizable(*box_image1);
			window_data_image1->end();
			window_data_image1->show();
}
void CreateCustomerCB(Fl_Widget* w, void* p)
{
	stringstream ss;
	string test;
	ss << count_customer;
	test = ss.str();
	data_4 = data_4 + "Customer No:" + test + '\n' + "------------------------------------------------------\n" + customer_widget->customer_name()+'\n'+customer_widget->customer_number()+'\n'+customer_widget->wallet()+ '\n'+"------------------------------------------------------\n";
	storage_data.push_back(customer_widget->customer_name() + ","+customer_widget->customer_number() + ","+ customer_widget->wallet());
	count_customer++;
}
void CreateSalesAssociate(Fl_Widget* w, void* p)
{
	stringstream ss;
	string test;
	ss << count_associate;
	test = ss.str();
	data_5 = data_5 + "Sale's Associate No:" + test + '\n' + "------------------------------------------------------\n" + sales_associate_widget->associate_name() + '\n'+sales_associate_widget->employee_number()+ '\n' + "------------------------------------------------------\n";
	sales_storage.push_back(sales_associate_widget->associate_name() + "," + sales_associate_widget->employee_number());
	count_associate++;
}
void DisplayOrderCB(Fl_Widget* w, void* p)
{
	int a = Fl::w();
	int h = Fl::h();
	window_order = new Fl_Window(a * 100, h * 100, "Dsiplay Order");
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
	window_data_defined = new Fl_Window(a * 100, h * 100, "Display Robot Model"); 
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
	window_sales = new Fl_Window(a * 100, h * 100, "Display Sale's Associate");
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
	window_customer = new Fl_Window(a * 100, h * 100, "Display Customer");
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
		window_data = new Fl_Window(a*100, h*100,"Display Robot part");
		const char * Data_1 = (data_1.c_str());
		Fl_Scroll *scroll = new Fl_Scroll(0, 0, a*100, h*100, "Display Robot Part");
		Fl_Multiline_Output *outputData =new Fl_Multiline_Output(0,0,a*100,h*100);
		outputData->value(Data_1);
		window_data->resizable(*outputData);
		robot_part_widget->hide();
		window_data->end();
		window_data->show();
}
Fl_Menu_Item menuitems[] = {
	{ "&Create",0,0,0,FL_SUBMENU },
	{ "&Create Robot Part", FL_ALT + 'a', (Fl_Callback *)showRobotPartCB },
	{ "&Create Robot Model", FL_ALT + 'c', (Fl_Callback *)showDefinedRobotPartCB},
	{ "&Create and Display Image", FL_ALT + 'e', (Fl_Callback *)ShowImage },
	{ "&Create Customer", FL_ALT + 'f', (Fl_Callback *)customer_history },
	{ "&Create Sales Associate", FL_ALT + 'h', (Fl_Callback *)sales_info },
	{ "&Create Order", FL_ALT + 'j', (Fl_Callback *)order_infoCB },
	{ 0 },
	{ "&View",0,0,0,FL_SUBMENU },
	{ "&Display Robot Part", FL_ALT + 'b', (Fl_Callback *)DisplayPartCB },
	{ "&Display Robot Model", FL_ALT + 'd', (Fl_Callback *)DisplayModelCB },
	{ "&Display Customer", FL_ALT + 'g', (Fl_Callback *)DisplayCustomerInfoCB },
	{ "&Display Sale's Associate", FL_ALT + 'i', (Fl_Callback *)DisplaySalesCB },
	{ "&Display Order", FL_ALT + 'k', (Fl_Callback *)DisplayOrderCB },
	{ 0 },
	{ "&Help",0,0,0,FL_SUBMENU },
	{ "&About", FL_ALT + 'k', (Fl_Callback *)HelpCB },
	{ 0 },
	{ 0 }
};
int main() {
	const int w = 640;
	const int h = 480;
	robot_part_widget = new robot_part{};
	robotModel_widget = new robotModel{};
	robot_picture_widget = new robot_pictures{};
	customer_widget = new customer{};
	sales_associate_widget = new sales_associate{};
	order_widget = new order{};
	window = new Fl_Window(w, h, "Welcome to Robbie Robot Shop");
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