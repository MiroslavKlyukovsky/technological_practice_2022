#ifndef CLASS_STUDENT
#define CLASS_STUDENT
#include <string>  
enum student_names{//Перелічуваний тип (10 імен)
	Ivan,            //0
	Oleksiy,  	 
	Petro, 		 
	Kateryna, 	 
	Alina,
	Alla,
	Bohdana,
	Daryna,
	Inna,
	Kseniya	 	 //9
};

std::string get_name(student_names name){//Функція для отримання типу рядок з типу перелічуваного
	switch (name)
	{
	case Ivan:
		return "Ivan";
		break;
	case Oleksiy:
		return "Oleksiy";
		break;
	case Petro:
		return "Petro";
		break;
	case Kateryna:
		return "Kateryna";
		break;
	case Alina:
		return "Alina";
		break;
	case Alla:
		return "Alla";
		break;
	case Bohdana:
		return "Bohdana";
		break;
	case Daryna:
		return "Daryna";
		break;
	case Inna:
		return "Inna";
		break;
	case Kseniya:
		return "Kseniya";
		break;
	default:
		return "Unknown";
		break;
	}
};

student_names get_enum_name(std::string name){//имання типу рядок з типу перелічуваного
        if(name == "Ivan"){
                return Ivan;}      
        if( name == "Oleksiy"){
                return Oleksiy;
	}
        if( name == "Petro"){
                return Petro;
        }
        if( name == "Kateryna"){
                return Kateryna;
        }
        if( name == "Alina"){
                return Alina;
        }
        if( name == "Alla"){
                return Alla;
        }
        if( name == "Bohdana"){
                return Bohdana;
        }
        if( name == "Daryna"){
                return Daryna;
        }
        if( name == "Inna"){
                return Inna;
	}
        if( name == "Kseniya"){
                return Kseniya;
	}
	return Ivan;
};

class Student{//Оголошення типу Student
	private:
		student_names name = Ivan;
		float avarage_grade = -1;
		bool dancing = false;
	public:
		Student();
		Student(student_names, float, bool);
		
		void setName(student_names);
		void setAvgGrade(float);
		void setDancing(bool);
		
		student_names getName();
		float getAvgGrade();
		bool getDancing();
};

Student::Student(){
	this->name = Ivan;
	this->avarage_grade = 10;
	this->dancing = false;
};

Student::Student(student_names name, float avarage_grade, bool dancing){//Конструктор студента, з перевіркою вводу
	if( (avarage_grade < 0) or (avarage_grade > 100) ){
		std::cout << avarage_grade << std::endl;
		throw "WRONG avarage_grade in CONSTRUCTOR";//Перевірка
	}
	this->name = name;
	this->avarage_grade = avarage_grade;
	this->dancing = dancing;
};

void Student::setName(student_names name){//Метод для задання імені студента
	this->name = name;
};

void Student::setAvgGrade(float avarage_grade){//Метод для задання середнього балу студента
	if(!( ( avarage_grade >= ((float)0) ) and (avarage_grade <= ((float)100) )) ){
		throw "WRONG avarage_grade in setAvgGrade()";
	}
	this->avarage_grade = avarage_grade;
};

void Student::setDancing(bool dancing){//Метод для задання стану танцю студента
	this->dancing = dancing;
};

student_names Student::getName(){//Метод отримання імені студента
	return name;
};

float Student::getAvgGrade(){//Метод отримання середнього балу студента
	return avarage_grade;
};

bool Student::getDancing(){//Метод для отримання стану танцю студента
	return dancing;
};
#endif
