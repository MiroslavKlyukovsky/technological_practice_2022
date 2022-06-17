#ifndef CLASS_LIST
#define CLASS_LIST
#include "class_student.cpp"
#include <typeinfo>
class List{//Створення АТД
	private:
        	class Node{//Внутрішній клас Node(вузол двоспрямованого списку)
        		public:
			Node* pPrevious;
                	Node* pNext;
                	Student Data;
                	Node(Student Data, Node* pPrevious = nullptr, Node* pNext = nullptr){
                        	this->Data = Data;
                        	this->pPrevious = pPrevious;
				this->pNext = pNext;
                	}
       	 	};

		class Iterator{//Внутрішній клас Iterator(власний ітератор для ітерації по списку в прямому порядку)
			public:
    			using iterator_category = std::forward_iterator_tag;
   			using difference_type   = int;
    			using value_type        = Node;
    			using pointer           = Node*;  
    			using reference         = Node&;  
			Iterator(pointer ptr) : m_ptr(ptr) {}
			reference operator*() const {return *m_ptr;}
    			Student operator->() {return m_ptr->Data;}
    			Iterator& operator++(){this->m_ptr = this->m_ptr->pNext;return *this;}  
    			friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    			friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };   	
			private:
			pointer m_ptr;
		};

		int Size;
        	Node* head;
		Node* tail;
	public:
                List();
		~List();
                void push_back(Student Data);
                bool remove_at(const int index);
                Student& operator [](const int index);
                int size();
                Iterator begin() { return Iterator(head);}//Опис метода для отримання ітератора вказуючого на початок
                Iterator end()   { return Iterator(nullptr);}//Опис метода для отримання ітератор вказуючого на елемент для зупинки
		List new_mixed();
		int find_count();
};

List::List(){//Конструктор без параметрів(базовий)
	Size = 0;
	head = nullptr;
	tail = nullptr;
};

void List::push_back(Student Data){//Метод для додавання елемента в кінець АТД(списку), має перевірку вводу
	if( typeid(Data) != typeid(Student) ){
 		throw "WRONG INPUT in PUSH_BACK";//Перевірка
	}
	if (head == nullptr){
                head = new Node(Data);
        }else{
		if(Size == 1){
		  	this->tail = new Node(Data,this->head);
			this->head->pNext = this->tail;
		}else{
                	this->tail->pNext = new Node(Data,this->tail);
			this->tail = this->tail->pNext;
		}
        }
        Size++;
};

bool List::remove_at(const int index){//Метод для видалення елементу по індексу, має перевірку вводу
        if(!((index < Size) and (index >= 0))){ 
 		throw "WRONG INDEX in REMOVE_AT";//Перевірка
	}
	if((Size/2) > index){//Оптимізація роботи(ітерування до бажаного вузла з голови або хвоста, в залежності від індексу)
		Node* tmp = head;
		for(int i = 0; i < index; i++){
			tmp = tmp->pNext;
		}
		if(tmp->pPrevious != nullptr){tmp->pPrevious->pNext = tmp->pNext;}
		if(tmp->pNext != nullptr){tmp->pNext->pPrevious = tmp->pPrevious;}
		if(tmp==head){head = tmp->pNext;}
		delete tmp;
		Size--;
		return true;

	}else{	
		if(tail == nullptr){delete head; Size--; return true;}

		Node* tmp = tail;

		for(int i = Size - index; i > 1; i--){
			if(tmp->pPrevious != nullptr){tmp = tmp->pPrevious;}
		}
		if(tmp->pPrevious != nullptr){tmp->pPrevious->pNext = tmp->pNext;}
		if(tmp->pNext != nullptr){tmp->pNext->pPrevious = tmp->pPrevious;}
		if(tmp==tail){tail = tmp->pPrevious;}
		delete tmp;
		Size--;
		return true;
	}
	return false;
};

Student& List::operator [] (const int index){//Метод для доступу до елемента за індексом(читання/редагування), має перевірку вводу
      	if(!((index < Size) and (index >= 0))){ 
 		throw "WRONG INDEX in OPERATOR []";//Перевірка
	}
	if((Size/2) > index){//Оптимізація роботи(ітерування до бажаного вузла з голови або хвоста, в залежності від індексу)
		Node* tmp = head;
		for(int i = 0; i < index; i++){
			tmp = tmp->pNext;
		}
		return tmp->Data;
	}else{
		Node* tmp = tail;
		for(int i = Size - index; i > 1; i--){
			tmp = tmp->pPrevious;
		}
		return tmp->Data;
	}		
};

int List::size(){//Метод для отримання кількості вузлів АТД
	return Size;
};

List List::new_mixed(){//Метод для отримання нового зміненого АТД
	List tmp;
	for (auto elem : *this){
                tmp.push_back(elem.Data);
        } 
	
	for(int i = 0; i < (Size/2); i+=2){
		tmp[i] = (*this)[i+1];
		tmp[i+1] = (*this)[i];
	}
	return tmp;
};

int List::find_count(){//Метод для пошуку за властивістю вказаною в таблиці варіанту(відмінники танцюристи)
	int tmp = 0;
	for (auto elem : *this){
               if((elem.Data.getAvgGrade() > 90) and elem.Data.getDancing()){
	       		tmp++;
	       }
        } 
	return tmp;
};

List::~List(){//Деструктор АТД
	for(int i = Size; i > 0; i--){
		remove_at(0);
	}
};
#endif
