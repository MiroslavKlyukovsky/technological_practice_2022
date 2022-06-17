#include <iostream>
#include <vector>
#include "class_list.cpp"
#include "class_student.cpp"
//Проект складається з main.cpp, class_student.cpp and class_list.cpp
void show(List& list);
int main(int argc, char* argv[]){
	if(argc != 1){
	std::string string = argv[1];
	if(string == "-help"){
		std::cout << "Hello! I will give you short tutor how to use this small program." << std::endl;
		std::cout << "It can be a bit buggy, sorry for that." << std::endl;
		std::cout << "You have one structure(at some point like std::list)." << std::endl;
		std::cout << "You can /add students, /remove students, /show all students data, /find number of students with speciall properties," << std::endl;
		std::cout << "also you can quit with /end." << std::endl;
		std::cout << "Here is examples of commands:" << std::endl;
		std::cout << "/add -Inna -95.55 -true" << std::endl;
		std::cout << "/add -name -avarage_grade -dancing_status (Name must start with capital and after lowcase letters!)" << std::endl;
		std::cout << "/remove -0" << std::endl;
		std::cout << "/remove -index (starts at 0!)" << std::endl;
		std::cout << "/show" << std::endl;
		std::cout << "/find" << std::endl;
		std::cout << "/end" << std::endl;
		std::cout << "Also names must be: Ivan, Oleksiy, Petro, Kateryna, Alina, Alla, Bohdana, Daryna, Inna, Kseniya." <<  std::endl;
		std::cout << "Also grades must be from 10 to 100." <<  std::endl;
		std::cout << "Also dancing status must be true or false." <<  std::endl;
		std::cout << "Start program without -help parameter to work with it." << std::endl;
		return 0;
	}}


	List list;
	std::string str = "";
	std::getline(std::cin, str);
	str= str + "               ";
	
	while(str != "/end               " and str != "/end"){//ОБЗЕРВЕР(слідкує за вводом і виконує дії зі списком)
		
		str = str + "               ";
		
		if(str.substr(0,4) == "/add"){//Випадок додавання елемента
			
			int count_of_flags = 0;
			std::string one = "",two = "", three = "";
			
			for(int i = 4; i < str.size(); i++){
				if(str[i] == '-'){count_of_flags++;}else{
				
					if(count_of_flags == 1){
						if(str[i] != ' '){
							one.push_back(str[i]);
						}	
					}
					if(count_of_flags == 2){
						if(str[i] != ' '){
							two.push_back(str[i]);
						}	
					}
					if(count_of_flags == 3){
						if(str[i] != ' '){
							three.push_back(str[i]);
						}	
					}
			    	}
			}

			float shit = std::stof(two);
			Student sdnt(get_enum_name(one), shit, three[0]=='t');
			list.push_back(sdnt);
			show(list);
			std::getline(std::cin, str);
			continue;
		}

		if(str.substr(0,7) == "/remove"){//Випадок видалення елемента
			int count_of_flags = 0;
			std::string one = "";

			for(int i = 7; i < str.size(); i++){
				if(str[i] == '-'){count_of_flags++;}else{
					if(count_of_flags == 1){
						if(str[i] != ' '){
							one.push_back(str[i]);
						}	
					}
				}
		    	}
		    list.remove_at( std::stoi(one) );
		    show(list);
		    std::getline(std::cin, str);
	            continue;	
		}

		if(str.substr(0,5) == "/show"){//Випадок показу всих елементів
			show(list);
			std::getline(std::cin, str);
			continue;	
		}

		if(str.substr(0,5) == "/find"){//Випадок пошуку відмінників танцюристів
			std::cout << list.find_count() << std::endl;
			std::getline(std::cin, str);
			continue;	
		}
		
		if(str.substr(0,4) == "/end               "){//Випадрк кінця роботи
			break;
		}

		if(str.substr(0,4) != "/end               "){//Випадок коли введено щось незрозуміле
			std::cout << "What do you mean? Try again." << '\n';
			std::getline(std::cin, str);
		}
	}
	
	return 0;
};

void show(List& list){//Функція показу
	std::vector<std::string> vec_string;
	std::vector<bool> vec_bool;
	std::vector<float> vec_float;
	if(list.size()){
		for (auto elem : list){
			vec_string.push_back(get_name(elem.Data.getName()));
			vec_float.push_back(elem.Data.getAvgGrade());		
			vec_bool.push_back(elem.Data.getDancing());
		}
		std::cout << "<<   Name   >> " << " <<   Avarage Grade   >> " << " <<   Dancing   >>" << std::endl;;
		for(int i = 0; i < list.size(); i++){	
			std::cout << "     " << vec_string[i];
			std::cout << "                " << vec_float[i];
			std::cout << "                    " << vec_bool[i]   << std::endl;
		}
	}else{
		std::cout << "<<   Name   >> " << " <<   Avarage Grade   >> " << " <<   Dancing   >>" << std::endl;;
	}
};
