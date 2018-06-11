
#include "sort.h"
#include "well512.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //tokenizer

void sort::sorting() {

	std::string temp = "";
	std::string a_num = "";
	std::string sixty_string_temp = "";
	std::string yet_bwt = "";
	std::ifstream in_f;
	std::string ar_temp = ""; 

	for (int i = 0; i < 16; i++) {
		if (i == 0) in_f.open("bwt_pre_sort_aa.txt"); else if (i == 1) in_f.open("bwt_pre_sort_ac.txt"); else if (i == 2) in_f.open("bwt_pre_sort_ag.txt"); else if (i == 3) in_f.open("bwt_pre_sort_at.txt");
		else if (i == 4) in_f.open("bwt_pre_sort_ca.txt"); else if (i == 5) in_f.open("bwt_pre_sort_cc.txt"); else if (i == 6) in_f.open("bwt_pre_sort_cg.txt"); else if (i == 7) in_f.open("bwt_pre_sort_ct.txt");
		else if (i == 8) in_f.open("bwt_pre_sort_ga.txt"); else if (i == 9) in_f.open("bwt_pre_sort_gc.txt"); else if (i == 10) in_f.open("bwt_pre_sort_gg.txt"); else if (i == 11) in_f.open("bwt_pre_sort_gt.txt");
		else if (i == 12) in_f.open("bwt_pre_sort_ta.txt"); else if (i == 13) in_f.open("bwt_pre_sort_tc.txt"); else if (i == 14) in_f.open("bwt_pre_sort_tg.txt"); else if (i == 15) in_f.open("bwt_pre_sort_tt.txt");
		std::vector<std::string> sixty_string;
		std::vector<std::string> temp_bwt;
		std::vector<std::string> temp_ar_num;
		if (in_f.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드

			while (getline(in_f, temp)) {
				if (temp != "\n") {
					std::istringstream iss(temp);
					getline(iss, a_num, ' '); getline(iss, sixty_string_temp, ' '); getline(iss, yet_bwt, ' ');
					temp_ar_num.push_back(a_num);
					//std::cout << std::stoi(a_num) << std::endl;
					sixty_string.push_back(sixty_string_temp);
					temp_bwt.push_back(yet_bwt);

				}
				else {
					break;
				}
			}
		}
		std::cout << "정렬 준비 끝" << std::endl;
		//	bwt 생성
		int a, b, c; std::string temp_bwt_s = ""; int percent = 0;
		for (a = 0; a < sixty_string.size() - 1; a++) {
			for (b = 0, c = 0; b < sixty_string.size() - 1 - a; b++) {  //앞자리가 같은경우 뒷자리 비교를 위해 b, c 변수 2개 사용
				if (sixty_string[b][0] == '$') {

				}

				else if (sixty_string[b].compare(sixty_string[b + 1]) < 0) {
					//c = 0;

				}
				else if (sixty_string[b].compare(sixty_string[b + 1]) > 0) {
				//	c = 0;
				//	std::cout << "교체중" << arrange_number[b] << " " << arrange_number[b + 1] << std::endl;
					temp = sixty_string[b]; ar_temp = temp_ar_num[b];	temp_bwt_s = temp_bwt[b];
					sixty_string[b] = sixty_string[b + 1]; temp_ar_num[b] = temp_ar_num[b + 1]; temp_bwt[b] = temp_bwt[b + 1];
					sixty_string[b + 1] = temp; temp_ar_num[b + 1] = ar_temp; temp_bwt[b + 1] = temp_bwt_s;
				//	std::cout << "교체중" << arrange_number[b] << " " << arrange_number[b + 1] << std::endl;

				}
				else {  //same case, 뒤의 자리를 계속 비교하기위해 
				//	if (c == 60) {
					std::cout << b << std::endl;
						std::cout << "비교길이를 더 늘려주셔야합니다." << std::endl;
						system("pause");
					//}
					//b--; c++;
				}
				
			}
			if (a % 100 == 0)
				std::cout << percent++ << "진행중" << std::endl;
		}
		std::cout << i << "차 "<<"정렬 끝" << std::endl;
		for (int p = 0; p < sixty_string.size(); p++) {
			arrange_number.push_back(std::stoi(temp_ar_num[p]));
			pre_bwt.push_back(sixty_string[p]);
			bwt.push_back(temp_bwt[p]);
		}
		in_f.close();
	}
	std::cout << "for 문 종료" << std::endl;
	std::ofstream out_bwt("perfect_bwt.txt");
	for (int i = 0; i < bwt.size(); i++) {
		out_bwt << arrange_number[i] << " " << " " << pre_bwt[i] << " " << bwt[i] << std::endl;
	}
	out_bwt.close();
}
void sort::make_bwt_rank() {
	std::string temp = "";
	std::string a_num = "";
	
	std::string read_pre_bwt = "";
	std::string read_bwt = "";
	std::ifstream in_f("perfect_bwt.txt");
	int rank_a = 0; int rank_c = 0; int rank_g = 0; int rank_t = 0;
	int pre_rank_a = 0; int pre_rank_c = 0; int pre_rank_g = 0; int pre_rank_t = 0;
	int next_index_num = 0; // make bwt_path
		if (in_f.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드

			while (getline(in_f, temp)) {
				if (temp != "\n") {
					std::istringstream iss(temp);
					getline(iss, a_num, ' '); getline(iss, read_pre_bwt, ' ');  getline(iss, read_pre_bwt, ' '); getline(iss, read_bwt, ' ');
					arrange_number.push_back(std::stoi(a_num));
					pre_bwt.push_back(read_pre_bwt);
					bwt.push_back(read_bwt);
				}
				else {
					break;
				}
			}
		}
		in_f.close();
		std::cout << "bwt_rank, bwt_path 만들 준비 끝" << std::endl;

		std::ofstream out_f0("pre_bwt_rank.txt");
		out_f0 << 0 << '\n'; //$ number
		for (int i = 0; i < pre_bwt.size(); i++) {
			if (pre_bwt[i][0] == 'A') {
				out_f0 << pre_rank_a << '\n';
				pre_bwt_rank.push_back(pre_rank_a++);
			}
			else if (pre_bwt[i][0] == 'C') {
				out_f0 << pre_rank_c << '\n';
				pre_bwt_rank.push_back(pre_rank_c++);
			}
			else if (pre_bwt[i][0] == 'G') {
				out_f0 << pre_rank_g << '\n';
				pre_bwt_rank.push_back(pre_rank_g++);
			}
			else if (pre_bwt[i][0] == 'T') {
				out_f0 << pre_rank_t << '\n';
				pre_bwt_rank.push_back(pre_rank_t++);
			}
		}
		std::cout << pre_bwt_rank.size() << std::endl;
		out_f0.close();


		std::ofstream out_f("bwt_rank.txt");
		for (int i = 0; i < bwt.size(); i++) {
			if (bwt[i] == "A") {
				out_f << rank_a << '\n';
				bwt_rank.push_back(rank_a++);

			}else if (bwt[i] == "C") {
				out_f << rank_c << '\n';
				bwt_rank.push_back(rank_c++);
			}else if (bwt[i] == "G") {
				out_f << rank_g << '\n';
				bwt_rank.push_back(rank_g++);
			}else if (bwt[i] == "T") {
				out_f << rank_t << '\n';
				bwt_rank.push_back(rank_t++);
			}else {
				out_f << 0 << '\n';
				bwt_rank.push_back(0);
			}		
		}

		out_f.close();
		bwt_path.assign(bwt.size(), 0);
		std::cout << "bwt_rank 생성" << std::endl;
		std::ofstream out_f2("bwt_path.txt");

		int count = 0;
		while (true) {
			
			if (bwt[next_index_num] == "$") {
				std::cout << "복원 완료" << std::endl;
				bwt_path[next_index_num] = 0;

				break;
			}

		//	original_sequence.push_back(bwt[next_index_num][0]);




			for (int i = 0; i < bwt.size(); i++) {
		
				if (pre_bwt[i][0] == bwt[next_index_num][0] && pre_bwt_rank[i] == bwt_rank[next_index_num]) { //문자와 문자의 위치가 같은것 ex) a1 = a1 , a1 != a2
					
			//		std::cout << pre_bwt[i] << " vs " << bwt[next_index_num] << " and " << pre_bwt_rank[i] << " vs " << bwt_rank[next_index_num] << " and " << next_index_num << " vs " << i << std::endl;

					bwt_path[next_index_num] = i;
					next_index_num = i;
					break;
				}
			}
			std::cout << count++ << std::endl;
		}
	//	original_sequence.push_back('$');

		for (int i = 0; i < pre_bwt_rank.size(); i++) {
			out_f2 << bwt_path[i] << '\n';
		}
		out_f2.close();
	
		std::cout << "문서 생성 완료 "<< std::endl;
}
void sort::test_compare() {
	
	std::string temp = "";
	std::string a_num = "";

	std::string read_pre_bwt = "";
	std::string read_bwt = "";
	std::ifstream in_f("perfect_bwt.txt");
	
	int rank_a = 0; int rank_c = 0; int rank_g = 0; int rank_t = 0;
	int pre_rank_a = 0; int pre_rank_c = 0; int pre_rank_g = 0; int pre_rank_t = 0;
	int next_index_num = 0; // make bwt_path
	if (in_f.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드

		while (getline(in_f, temp)) {
			if (temp != "\n") {
				std::istringstream iss(temp);
				getline(iss, a_num, ' '); getline(iss, read_pre_bwt, ' ');  getline(iss, read_pre_bwt, ' '); getline(iss, read_bwt, ' ');
				arrange_number.push_back(std::stoi(a_num));
				pre_bwt.push_back(read_pre_bwt);
				bwt.push_back(read_bwt);
			}
			else {
				break;
			}
		}
	}
	in_f.close();
	std::ifstream in_f2("bwt_path.txt");
	if (in_f2.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드

		while (getline(in_f2, temp)) {
			if (temp != "\n") {
				bwt_path.push_back(std::stoi(temp));
			}
			else {
				break;
			}
		}
	}
	std::cout << "path 번호받음" << bwt_path.size() << std::endl;
	in_f2.close();

	int n_num = 0;
	original_sequence.push_back('$');
	for (int i = 0; i < bwt.size()-1; i++) {
		original_sequence.push_back(bwt[n_num][0]);
		n_num = bwt_path[n_num];
	}
	
	std::cout << "문자열 복원 완료" << std::endl;

}


void sort::make_pattern_string(int p_len, int p_num, std::string abc) {
	Well512Random rannum;
	std::ofstream out_f("random_pattern.txt");
	for (int i = 0; i < p_num; i++) {
		pattern_string.push_back(abc.substr(rannum.GetValue(0, abc.length() - p_len), p_len));
		out_f << pattern_string[i] << '\n';
	}
	out_f.close();
}
void sort::assign() {
	std::string temp = "";
	std::string a_num = "";

	std::string read_pre_bwt = "";
	std::string read_bwt = "";
	std::ifstream in_f("perfect_bwt.txt");
	bool check_a = true; bool check_c = true;	bool check_g =  true; bool check_t =  true;
 	int n = 0;
	if (in_f.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드

		while (getline(in_f, temp)) {
			if (temp != "\n") {
				std::istringstream iss(temp);
				getline(iss, a_num, ' '); getline(iss, read_pre_bwt, ' ');  getline(iss, read_pre_bwt, ' '); getline(iss, read_bwt, ' ');
				arrange_number.push_back(std::stoi(a_num));
				pre_bwt.push_back(read_pre_bwt);
				bwt.push_back(read_bwt);
			}
			else {
				break;
			}
			if (pre_bwt[n][0] == 'A' && check_a) {
				start_numa = n; check_a = false;
			}else if (pre_bwt[n][0] == 'C' && check_c) {
				start_numc = n; check_c = false;
			}else if (pre_bwt[n][0] == 'G' && check_g) {
				start_numg = n; check_g = false;
			}else if (pre_bwt[n][0] == 'T' && check_t) {
				start_numt = n; check_t = false;
			}			
			n++;
		}
		/*std::cout << start_numa << std::endl;
		std::cout << start_numc << std::endl;
		std::cout << start_numg << std::endl;
		std::cout << start_numt << std::endl;*/

	}
	in_f.close();
	std::ifstream in_f2("bwt_path.txt");
	if (in_f2.is_open()) {
		while (getline(in_f2, temp)) {
			if (temp != "\n") {
				bwt_path.push_back(std::stoi(temp));
			}
			else {
				break;
			}
		}
	}
	in_f2.close();
	original_sequence_brute.assign(bwt.size(), "-");
	original_sequence_bwt.assign(bwt.size(), "-");

	std::cout << "rebuild 준비 끝" << bwt_path.size() << std::endl;
}

void sort::rebuild_bwt() {

	int n_num = 0;
	int check = 0; int start_num = 0;
	for (int a = 0; a < pattern_string.size(); a++) {		
		if (pattern_string[a][pattern_string[0].length() - 1] == 'A') { //각 문자 시작위치를 지정해놓음으로 시간 절약
			start_num = start_numa;
		}
		else if (pattern_string[a][pattern_string[0].length() - 1] == 'C') {
			start_num = start_numc;
		}
		else if (pattern_string[a][pattern_string[0].length() - 1] == 'G') {
			start_num = start_numg;
		}
		else if (pattern_string[a][pattern_string[0].length() - 1] == 'T') {
			start_num = start_numt;
		}
		for (int b = start_num; b < pre_bwt.size(); b++) {
			check = 0;
			int c = pattern_string[0].length() - 1; // last index of pattern_string
			if (pre_bwt[b][0] == pattern_string[a][c]) { // start search
	//			std::cout << b << "번째에서" << pattern_string[a] << std::endl;
				n_num = bwt_path[b];
				c = c - 1;
				while (c >= 0) {
					if (pre_bwt[n_num][0] != pattern_string[a][c]) {
					//	std::cout << bwt[n_num][0] << " vs " << pattern_string[a][c] << " break " << std::endl;
					//	std::cout << " ?? " << std::endl;
						break;
					}
				//	std::cout << pre_bwt[n_num][0] << " vs " << pattern_string[a][c] << std::endl;
					c--; 		n_num = bwt_path[n_num];
					if (c < 0) {
						for (int i = 0; i < pattern_string[0].length(); i++) {
						//	std::cout << bwt.size() - 1 - arrange_number[n_num] + i << "에" << pattern_string[a][i] << "입력" << std::endl;
							original_sequence_bwt[bwt.size() - arrange_number[n_num] + i] = pattern_string[a][i];
						}
						check = 1;
						n_num = 0; break;
					}
				}
			}
			if (check == 1) {
				break;
			}
		}
	//	std::cout << a << " 번 진행" << std::endl;
	}
	std::ofstream out_f("test_original.txt");

	for (int i = 0; i < original_sequence_bwt.size(); i++) {
		out_f << original_sequence_bwt[i];
	}
	out_f.close();
}
void sort::rebuild_bwt_miss() {

	int n_num = 0;
	int check = 0; int start_num = 0; int miss_check = 0;
	for (int a = 0; a < pattern_string.size(); a++) {
		if (pattern_string[a][pattern_string[0].length() - 1] == 'A') { //각 문자 시작위치를 지정해놓음으로 시간 절약
			start_num = start_numa;
		}
		else if (pattern_string[a][pattern_string[0].length() - 1] == 'C') {
			start_num = start_numc;
		}
		else if (pattern_string[a][pattern_string[0].length() - 1] == 'G') {
			start_num = start_numg;
		}
		else if (pattern_string[a][pattern_string[0].length() - 1] == 'T') {
			start_num = start_numt;
		}
		for (int b = start_num; b < pre_bwt.size(); b++) {
			check = 0;	miss_check = 0;
			int c = pattern_string[0].length() - 1; // last index of pattern_string
			if (pre_bwt[b][0] == pattern_string[a][c]) { // start search
														 //			std::cout << b << "번째에서" << pattern_string[a] << std::endl;
				n_num = bwt_path[b];
				c = c - 1;
				while (c >= 0) {
					if (pre_bwt[n_num][0] != pattern_string[a][c] && miss_check >= 2) {
						break;
					}
					else if(pre_bwt[n_num][0] != pattern_string[a][c] && miss_check < 2){
						miss_check = miss_check + 1;
					}
					//	std::cout << pre_bwt[n_num][0] << " vs " << pattern_string[a][c] << std::endl;
					c--; 		n_num = bwt_path[n_num];
					if (c < 0) {
						for (int i = 0; i < pattern_string[0].length(); i++) {
							//	std::cout << bwt.size() - 1 - arrange_number[n_num] + i << "에" << pattern_string[a][i] << "입력" << std::endl;
							original_sequence_bwt[bwt.size() - arrange_number[n_num] + i] = pattern_string[a][i];
						}
						check = 1;
						n_num = 0; break;
					}
				}
			}
			if (check == 1) {
				break;
			}
		}
		//	std::cout << a << " 번 진행" << std::endl;
	}
	std::ofstream out_f("test_reconstruct_mutate_bwt.txt");

	for (int i = 0; i < original_sequence_bwt.size(); i++) {
		out_f << original_sequence_bwt[i];
	}
	out_f.close();
}
void sort::brute(std::string abc) {
	int check_dna = 0;
	for (int p = 0; p < pattern_string.size(); p++) {
		for (int a = 0; a <= abc.length() - pattern_string[0].length(); a++) {  //한칸 한칸 이동하면서 pattern 문자열의 길이만큼씩 문자열을 비교하는 방식
			check_dna = 0; //2번 이상되면 out
			for (int b = 0; b < pattern_string[0].length(); b++) {
				if (abc[a + b] != pattern_string[p][b]) {
					check_dna = check_dna + 1;
					if (check_dna == 3) {
						break;
					}
					else if (b == pattern_string[0].length() - 1) { //찾은 경우
						for (int i = 0; i < pattern_string[0].length(); i++) {
							original_sequence_brute[a + i] = pattern_string[p][i];
						}
					}
				}
				else {
					if (b == pattern_string[0].length() - 1) { //찾은 경우
						for (int i = 0; i < pattern_string[0].length(); i++) {
							original_sequence_brute[a + i] = pattern_string[p][i];
						}
					}
				}
			}
		}
	}
	std::ofstream out_f("test_reconstruct_mutate_brute.txt");

	for (int i = 0; i < original_sequence_bwt.size(); i++) {
		out_f << original_sequence_brute[i];
	}
	out_f.close();
}