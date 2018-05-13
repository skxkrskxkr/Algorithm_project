//Id : 2016112129 Name : taegun_kim


#include <iostream>
#include <fstream>
#include <cstdlib>  //난수생성위한 라이브러리
#include <ctime>

int main() {
	
	srand((unsigned int)time(NULL));


	std::ofstream txt_file("input.txt");
	
	for (int i = 0; i < 1000000; i++) {

		switch (rand() % 4) {
		case 0:
			txt_file << 'A'; break;
		case 1:
			txt_file << 'C'; break;
		case 2:
			txt_file << 'G'; break;
		case 3:
			txt_file << 'T'; break;
		default:
			break;
		}


	}
	std::cout << "생성완료" << std::endl;
	txt_file.close();
	system("pause");
	return 0;
}