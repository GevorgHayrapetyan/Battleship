#include <iostream>

class Board
{
private:
    char m_board_1[10][10];
public:
    Board();
    void draw();
    void set_ship(int,int,int,int);
};


Board :: Board()

{
    for ( int row = 0; row < 10; ++row){
        for (int col = 0; col < 10; ++col){
            m_board_1[row][col] = ' ';
        }
    }
}

void Board :: draw()
{
    std::cout << "       1   2   3   4   5   6   7   8   9  10 " << std::endl;
    std::cout << "     +---------------------------------------+" << std::endl;
    for ( int i = 0; i < 10; ++i ){
	std::cout << "   " << static_cast<char>(i+65)  << " |";
        for ( int j = 0; j < 10; ++j ) {
	    if (j != 9) {
                std::cout << " " << m_board_1[i][j] << " |";
	    }
	    else
            std::cout << " " << m_board_1[i][j];
        }
        std::cout << " |" << std::endl;
        std::cout << "     +---------------------------------------+" << std::endl;
    }
}

void Board :: set_ship(int x1, int y1, int x2, int y2)
{   if ( x1 == x2){
	    for ( int i = y1; i <= y2; ++i){
			m_board_1[x1 - 1][i - 1] = '*';
		}
	}
	else if (y1 == y2 ){
		for ( int i = x1; i <= x2; ++i){
			m_board_1[i - 1][y1 - 1] = '*'; 
		}
	}
	else 
		std::cerr<<"Invalid input  "<< x1<<" "<<y1<<" "<< x2<<" "<< y2 << std::endl;
}

static int count = 0;
class ship
{
        int m_x1;
        int m_y1;
        int m_x2;
        int m_y2;
        public:
                
};



int get_coordinate(int &x, int &y)
{
	x = 0;
	y = 0;
    char* str = new char[10];
    std::cin >> str;
    if ((str[0] >= 'A' && str[0] <= 'J' || str[0] >= 'a' && str[0] <= 'j') && str[1] != '\0'){
        x = static_cast<int>(str[0]);
		if ( x >= 97){
			x -= 96;
		}
		else{
			x -= 64;
		}
	}
	else{
        std::cerr<< "Invalid input 1\n";
		delete [] str;
		return -1;
	}
	for ( int i = 1; str[i] != '\0'; ++i){
		if ( str[i] >= '0' && str[i] <= '9'){
			(y *= 10, y += str[i] - '0');
			if ( y < 1 || y > 10){
				std::cerr << "Invalid coordinate 2 " << str <<std::endl;
				delete [] str;
				str = NULL;
				return -1;
			}
		}
		else{
			std::cerr << "Invalid coordinate 3  " << str << std::endl;
			delete [] str;
			str = NULL;
			return -1;
		}
	}
    delete [] str;
	str = NULL;
    return 0;   
}



void get_coordinate_of_ship(int &x1, int &y1, int &x2, int &y2)
{  
    while ( true ){
    	int x = get_coordinate(x1, y1);
		if ( x == 0 ){
			break;
	 	}
	}
	while ( true ){
    	int x = get_coordinate(x2, y2);
		if ( x == 0){
			break;
		}
	}
	std::cout << "(" << x1 << "," << y1 << ")" << " , " <<"(" << x2 << "," << y2 <<")"<< std::endl;

}

int main()
{
    Board a;
	a.draw();
	a.set_ship(7,6,10,6);
	a.draw();
	a.set_ship(6,1,6,4);
	a.draw();
	a.set_ship(2,1,2,1);
	a.draw();
    int x1 = 0;
    int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	get_coordinate_of_ship(x1,y1,x2,y2);
	a.set_ship(x1,y1,x2,y2);
	a.draw();
    
    return 0;
}
