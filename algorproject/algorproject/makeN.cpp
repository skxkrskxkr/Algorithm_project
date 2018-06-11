#include "makeN.h"

#include <fstream>
#include <string>
#include <vector>
void makeN::makeN_txt(std::string name){
	std::ofstream txt_file(name);
	for (int i = 0; i < N_length; i++) {

		switch (rannum.GetValue(0, 7)) {
		case 0: txt_file << 'A'; abc.push_back('A'); break;
		case 2: txt_file << 'A'; abc.push_back('A'); break;

		case 1: txt_file << 'C'; abc.push_back('C'); break;
		case 3: txt_file << 'C'; abc.push_back('C'); break;

		case 4: txt_file << 'G'; abc.push_back('C'); break;
		case 6: txt_file << 'G'; abc.push_back('C'); break;

		case 5: txt_file << 'T'; abc.push_back('C'); break;
		case 7: txt_file << 'T'; abc.push_back('C'); break;

		default:
			break;
		}
	}
	std::cout << "생성완료" << std::endl;
	txt_file.close();
}
void makeN::readN(std::string name) {
	std::ifstream txt_file(name);
	if (txt_file.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드
		getline(txt_file, abc);
	}
	else {
		std::cout << "read error" << std::endl;
	}
	abc.push_back('$');
}
void makeN::make_mutate() {
	std::string temp = abc;
	//2만개
	std::vector<int> miss_index;
	for (int i = 0; i < temp.length()-100; i++) {
		if (i % 100 == 0) {
			miss_index.push_back(rannum.GetValue(0, 99) + i);
			miss_index.push_back(rannum.GetValue(0, 99) + i);
		}		
	}
	//std::cout << miss_index.size() << std::endl;

	for (int i = 0; i < miss_index.size(); i++) {
		if (temp[miss_index[i]] == 'A') {
			temp[miss_index[i]] = 'C';
		}else if(temp[miss_index[i]] == 'C'){
			temp[miss_index[i]] = 'G';
		}else if (temp[miss_index[i]] == 'G') {
			temp[miss_index[i]] = 'T';
		}else if (temp[miss_index[i]] == 'T') {
			temp[miss_index[i]] = 'A';
		}
	}
	std::ofstream out_f("mutate_dna.txt");
	out_f << temp ;
	out_f.close();
	std::cout << "변이 생성 완료" << std::endl;
}
void makeN::read_mutate(std::string name) {
	std::ifstream txt_file(name);
	if (txt_file.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드
		getline(txt_file, abc_mutate);
	}
	else {
		std::cout << "read error" << std::endl;
	}
	abc_mutate.push_back('$');
}