#pragma once

#include <vector>


class sort {
public:
	int start_numa;
	int start_numc;
	int start_numg;
	int start_numt;

	std::string original_sequence;
	std::vector<std::string> original_sequence_bwt;
	std::vector<std::string> original_sequence_brute;

	std::vector<int> arrange_number;
	std::vector<int> pre_bwt_rank;
	std::vector<int> bwt_rank;
	std::vector<int> bwt_path;

	std::vector<std::string> pattern_string;

	std::vector<std::string> pre_bwt;
	std::vector<std::string> bwt;

	sort() {
		original_sequence = "";
		start_numa = 0;
		start_numc = 0;
		start_numg = 0;
		start_numt = 0;

		pre_bwt_rank.push_back(0); // $ ranknumber
	}
	void sorting();
	void make_bwt_rank(); 


	void test_compare(); //bwt생성이 잘 됬는지 확인
	void make_pattern_string(int p_len, int p_num, std::string abc); //len 길이 num 개수
	void assign();  //bwt search에 필요한 작업 및 원본 스트링 동적할당
	void rebuild_bwt(); //순수 bwt 체크용 알고리즘
	

	void brute(std::string abc); //missmatch 허용 알고리즘
	void rebuild_bwt_miss();
};