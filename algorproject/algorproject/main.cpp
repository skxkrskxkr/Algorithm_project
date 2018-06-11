
#include "separator.h"
#include "sort.h"
#include <time.h>

int main() {
	makeN make_dna = makeN(1000000);
	separator seprator_ = separator();
	sort sort_ = sort();

	//make_dna.makeN_txt("dna.txt");

	make_dna.readN("dna.txt");  //N 읽기  reference 생성
	//make_dna.make_mutate();  //my genome 생성 //readN을 실행 후 해야함 
	
	make_dna.read_mutate("mutate_dna.txt");

	//seprator_.make(make_dna.abc);   // 분할 생성
	//sort_.sorting();
	//sort_.make_bwt_rank();
	//sort_.test_compare();
	//

	//for (int i = 0; i < sort_.original_sequence.length(); i++) { // check bwt
	//	if (make_dna.abc[i] != sort_.original_sequence[sort_.original_sequence.length() - 1 - i]) {
	//		std::cout << "ㅋㅋ 다름" << make_dna.abc[i] << " vs " << sort_.original_sequence[sort_.original_sequence.length()-1-i] << " and i is" << i << std::endl;
	//	}
	//	
	//}

	sort_.make_pattern_string(60, 50000, make_dna.abc_mutate);
	sort_.assign();  //시퀀스 길이초기화 때문에 꼭 해줘야함
	clock_t p_time; double end_time;
	p_time = clock();
	std::cout << "brute 정렬 시간 체크 시작" << std::endl;
	//sort_.rebuild_bwt();
	sort_.brute(make_dna.abc);
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
	std::cout << "소요시간 " << end_time << "초 입니다." << std::endl;
	std::cout << std::endl;
	p_time = clock();
	std::cout << "bwt 정렬 시간 체크 시작" << std::endl;
	sort_.rebuild_bwt_miss();
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
	std::cout << "소요시간 " << end_time << "초 입니다." << std::endl;

	int count = 0; int count_diff = 0;
	for (int i = 0; i < sort_.original_sequence_bwt.size(); i++) { // check bwt
		
		if (make_dna.abc_mutate[i] != sort_.original_sequence_brute[i][0]) {
			count = count + 1;
			if (sort_.original_sequence_brute[i][0] != '-') {
				count_diff = count_diff + 1;
			}
		}
		else {
		}
	}
	std::cout << (float)count / sort_.original_sequence_bwt.size() * 100 << "% 불일치" << std::endl;
	std::cout << count_diff << "개 불일치" << std::endl;


	int count2 = 0; int count_diff2 = 0;
	for (int i = 0; i < sort_.original_sequence_bwt.size(); i++) { // check bwt

		if (make_dna.abc_mutate[i] != sort_.original_sequence_bwt[i][0]) {
			count2 = count2 + 1;
			if (sort_.original_sequence_bwt[i][0] != '-') {
				count_diff2 = count_diff2 + 1;
			}
		}
		else {
		}
	}
	std::cout << (float)count2 / sort_.original_sequence_bwt.size() * 100 << "% 불일치" << std::endl;
	std::cout << count_diff2 << "개 불일치" << std::endl;

	system("pause");
}