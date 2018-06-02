// ID : 2016112129 Name : Taegunkim

#include <iostream>
#include <fstream>
#include <string>
#include "merge.h"
#include <math.h>
#include <time.h>
#include <list>
class pre_rank_bwt {  //같은 문자의경우 a1,a2 rank로 구별 , arrange_number 등 필요한 정보를 가지고있는 자료구조
public:
	std::string bwt; std::string pre_bwt; std::string original_sequence;
	std::vector<int> pre_rank;
	std::vector<int> bwt_rank; //path를 구하기 위해 필요
	std::vector<int> bwt_path; // 이 문자가 pre_rank어디에있는지 나타내는 번호
	std::vector<int> arrange_number;

	std::vector<float> use_merge;

	std::string m_bwt(std::string abc) { //bwt 생성함수
		int ar_temp;
		std::string *bwt_array = new std::string[abc.length()];
		std::string temp; std::string bwt = "";
	
		for (int i = 0; i < abc.length(); i++) {
			bwt_array[i] = abc.substr(abc.length() - 1 - i) + abc.substr(0, abc.length() - 1 - i);
			arrange_number.push_back(abc.length()-1 -i);

			for (int k = 0; k < bwt_array[i].length(); k++) {
				if (bwt_array[i][k] == '$') {
					use_merge[i] = use_merge[i] * 10 + 1;
				}
				else if (bwt_array[i][k] == 'A') {
					use_merge[i] = use_merge[i] * 10 + 2;
				}
				else if (bwt_array[i][k] == 'C') {
					use_merge[i] = use_merge[i] * 10 + 3;
				}
				else if (bwt_array[i][k] == 'G') {
					use_merge[i] = use_merge[i] * 10 + 4;
				}
				else if (bwt_array[i][k] == 'T') {
					use_merge[i] = use_merge[i] * 10 + 5;
				}
			}
		//	std::cout << use_merge[i] << std::endl;
		}

		std::cout << std::endl;
		// 여기를 머지소트로 바꿔야함
		//int a, b, c;
		//for (a = 0; a < abc.length() - 1; a++) {
		//	for (b = 0, c = 0; b < abc.length() - 1 - a; b++) {  //앞자리가 같은경우 뒷자리 비교를 위해 b, c 변수 2개 사용
		//		if (bwt_array[b][c] < bwt_array[b + 1][c]) {
		//			c = 0;

		//		}
		//		else if (bwt_array[b][c] > bwt_array[b + 1][c]) {
		//			c = 0;
		//			temp = bwt_array[b]; ar_temp = arrange_number[b];
		//			bwt_array[b] = bwt_array[b + 1]; arrange_number[b] = arrange_number[b + 1];
		//			bwt_array[b + 1] = temp; arrange_number[b + 1] = ar_temp;
		//		}
		//		else {  //same case, 뒤의 자리를 계속 비교하기위해 
		//			b--; c++;
		//		}
		//	}
		//}
		
		MergeSort( 0, use_merge.size() - 1, use_merge, bwt_array);
		//for (int i = 0; i < use_merge.size(); i++) {
		//	std::cout << use_merge[i] << std::endl;
		//}
		for (int i = 0; i < abc.length(); i++) {
	//		std::cout << bwt_array[i] << std::endl;

			pre_bwt.push_back(bwt_array[i][0]);
			bwt.push_back(bwt_array[i][abc.length() - 1]);
		}

		//


		//std::cout << std::endl;
		//	std::cout << bwt << std::endl; 
		return bwt;
	}

	pre_rank_bwt() {

	}
	pre_rank_bwt(std::string T) {

		original_sequence = "";
		T = T + "$";

		pre_rank.assign(T.length(), 0); //0의 값으로 초기화
		bwt_rank.assign(T.length(), 0);
		bwt_path.assign(T.length(), 0);
		use_merge.assign(T.length(), 0);


		bwt = m_bwt(T); //bwt 생성 pre_bwt도 같이 생성됨


		for (int i = 0; i < T.length() - 1; i++) { //rank number
			if (pre_bwt[i] == pre_bwt[i + 1]) {
				pre_rank[i + 1] = pre_rank[i] + 1;
			}
		}
		int rank_num = 0;
		for (int a = 0; a < T.length(); a++) {
			for (int i = a + 1; i < T.length(); i++) {
				if (bwt[a] == bwt[i] && bwt_rank[i] == 0) {
					bwt_rank[i] = ++rank_num;
				}
			}
			rank_num = 0;
		}
	//	std::cout << std::endl;
	//	std::cout << "bwt = " << bwt << std::endl;

		//std::cout << "bwt_rank = ";
		//for (int i = 0; i < bwt.length(); i++) {
		//	std::cout << bwt_rank[i] << " ";
		//}
		//std::cout << std::endl;

	//	std::cout << "pre_bwt = " << pre_bwt << std::endl;

		//std::cout << "pre_rank = ";
		//for (int i = 0; i < bwt.length(); i++) {
		//	std::cout << pre_rank[i] << " ";
		//}
		//std::cout << std::endl;

	//	std::cout << "ar_number = ";
		for (int i = 0; i < bwt.length(); i++) {
	//		std::cout << arrange_number[i] << " ";
		}
	//	std::cout << std::endl;
	
	}

	void make_out_file() {
		std::ofstream in_pre_bwt("pre_bwt.txt");
		std::ofstream in_bwt("bwt.txt");
		
		std::cout << "문자열 복원작업 시작" << std::endl;
		int next_index_num = 0;
		while (true) {

			if (bwt[next_index_num] == '$') {
				std::cout << "복원 완료" << std::endl;
				bwt_path[next_index_num] = 0;
				break;
			}

			original_sequence.push_back(bwt[next_index_num]);

			//for (int i = original_sequence.length() - 1; i >= 0; i--) { //역순으로 들어가기때문에 거꾸로 출력해줘야 원래 문자열이 나온다.
			//	std::cout << original_sequence[i];
			//}


			for (int i = 0; i < bwt.length(); i++) {
				if (pre_bwt[i] == bwt[next_index_num] && pre_rank[i] == bwt_rank[next_index_num]) { //문자와 문자의 위치가 같은것 ex) a1 = a1 , a1 != a2
					bwt_path[next_index_num] = i;
					next_index_num = i;
					break;
				}
			}
		//	std::cout << std::endl;
		}
		for (int i = 0; i < pre_rank.size(); i++) {
			in_pre_bwt << pre_bwt[i] << " " << arrange_number[i] << '\n';
			in_bwt << bwt[i] << " " << bwt_path[i] << " " << arrange_number[i] << '\n';
		}
		in_pre_bwt.close();
		in_bwt.close();
	}

};





int main() {
	clock_t p_time; double end_time;
	p_time = clock();  //실행 시간을 측정하기 위해 함수가 실행될때 스타트

	std::ifstream in_f("input_solve4.txt");
	std::string T = "";

	if (in_f.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드
		getline(in_f, T); //파일이 한줄로 되어있기 때문에 한번만 읽는다.
	}
//	std::cout << T.length() << std::endl;
	pre_rank_bwt in_bwt(T); // bwt 생성


	in_bwt.make_out_file();

	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC; // 총 작업시간 체크
	std::cout << "끝난시간은 " << end_time << "초 입니다." << std::endl; // 작업시간 출력

	system("pause");
	return 0;
}