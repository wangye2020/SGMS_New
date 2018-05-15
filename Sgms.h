#include<iostream>
#include<string>
#include<vector>

class Sgms;

class Student
{
friend class Sgms;

private:
	std::string number;
	std::string name;
	double math,physics,english;

public:
	Student(std::string,std::string,double,double,double);
};

Student::Student(std::string number,std::string name,double math,double physics,double english)
{
	this->number = number;
	this->name = name;
	this->math = math;
	this->physics = physics;
	this->english = english;
}


class Sgms{
private:
	std::vector<Student> List;

public:
	void run();

	void add_record();
	void delete_record();
	void change_record();
	void search_record();
	void analyse_record();
	void sort_record();
	void file_record();

    void change_data(Student &,int);
};

void Sgms::run()
{
	while(1)
	{
		std::cout
		<< "---------------" << std::endl
		<< "    功能菜单    " << std::endl
		<< "---------------" << std::endl
		<< "1. 录入学生记录 " << std::endl
		<< "2. 删除学生记录" << std::endl
		<< "3. 修改学生记录" << std::endl
		<< "4. 查找学生记录" << std::endl
		<< "5. 成绩统计分析" << std::endl
		<< "6. 成绩高低排序" << std::endl
		<< "7. 成绩文件操作" << std::endl
		<< "0. 退出程序" << std::endl
		<< "---------------" << std::endl
		<< "请输入你要使用的功能编号: ";

		int button_1 = 0;
		std::cin >> button_1;

		if(button_1 == 0){break;}
		else if(button_1 == 1){add_record();}
		else if(button_1 == 2){delete_record();}
		else if(button_1 == 3){change_record();}
		else if(button_1 == 4){search_record();}
		else if(button_1 == 5){analyse_record();}
		else if(button_1 == 6){sort_record();}
		else if(button_1 == 7){file_record();}
	}
}


//各菜单函数↓

void Sgms::add_record()
{
    std::cout << "请分别输入：学号、姓名、数学成绩、物理成绩、英语成绩" << std::endl;
    std::string number, name;double math,physics,english;
    int button_2 = 0;
    do{
        std::cin >> number >> name >> math >> physics >> english;
        Student temp_stu(number,name,math,physics,english);
        List.push_back(temp_stu);
        std::cout << "！录入成功！" << std::endl
                << "1.继续录入 0.返回界面：";
        std::cin >> button_2;
    }while(button_2 == 1);
}

void Sgms::delete_record()
{
    std::cout << "请输入要删除的记录的学号或姓名:";
    std::string temp_data;
    int old_size = List.size();
    for(std::vector<Student>::iterator i = List.begin();i != List.end();i++)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            List.erase(i);
            std::cout << "！删除成功！" << std::endl;
        }
    }
    int new_size = List.size();
    if(old_size == new_size)std::cout << "！未找到此记录！" << std::endl;
}

void Sgms::change_record()
{
    std::cout << "请输入要修改的记录的学号或姓名:";
    std::string temp_data;
    int old_size = List.size();
    for(std::vector<Student>::iterator i = List.begin();i != List.end();i++)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            int button_2 = 0;
            std::cout << "请选择要修改的项目："
                    << "1.数学 2.物理 3.英语 0.返回：";
            std::cin >> button_2;
            switch (button_2) {
                case 1:change_data((*i),1);break;
                case 2:change_data((*i),2);break;
                case 3:change_data((*i),3);break;
                case 0:break;
            }
        }
    }
    int new_size = List.size();
    if(old_size == new_size)std::cout << "！未找到此记录！" << std::endl;
}

void Sgms::search_record()
{
    
}

void Sgms::analyse_record(){}
void Sgms::sort_record(){}
void Sgms::file_record(){}


//辅助函数↓

void Sgms::change_data(Student &temp_stu,int x)
{
    double data = 0;
    std::cout << "请输入修改后的内容：";
    std::cin >> data;
    switch (x) {
        case 1:temp_stu.math = data;break;
        case 2:temp_stu.physics = data;break;
        case 3:temp_stu.english = data;break;
    }
    std::cout << "！修改成功！" << std::endl;
}
