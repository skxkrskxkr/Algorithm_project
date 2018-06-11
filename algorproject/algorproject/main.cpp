
#include "separator.h"
#include "sort.h"
#include <time.h>

int main() {
	makeN make_dna = makeN(1000000);
	separator seprator_ = separator();
	sort sort_ = sort();

	//make_dna.makeN_txt("dna.txt");

	make_dna.readN("dna.txt");  //N �б�  reference ����
	//make_dna.make_mutate();  //my genome ���� //readN�� ���� �� �ؾ��� 
	
	make_dna.read_mutate("mutate_dna.txt");

	//seprator_.make(make_dna.abc);   // ���� ����
	//sort_.sorting();
	//sort_.make_bwt_rank();
	//sort_.test_compare();
	//

	//for (int i = 0; i < sort_.original_sequence.length(); i++) { // check bwt
	//	if (make_dna.abc[i] != sort_.original_sequence[sort_.original_sequence.length() - 1 - i]) {
	//		std::cout << "���� �ٸ�" << make_dna.abc[i] << " vs " << sort_.original_sequence[sort_.original_sequence.length()-1-i] << " and i is" << i << std::endl;
	//	}
	//	
	//}

	sort_.make_pattern_string(60, 50000, make_dna.abc_mutate);
	sort_.assign();  //������ �����ʱ�ȭ ������ �� �������
	clock_t p_time; double end_time;
	p_time = clock();
	std::cout << "brute ���� �ð� üũ ����" << std::endl;
	//sort_.rebuild_bwt();
	sort_.brute(make_dna.abc);
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
	std::cout << "�ҿ�ð� " << end_time << "�� �Դϴ�." << std::endl;
	std::cout << std::endl;
	p_time = clock();
	std::cout << "bwt ���� �ð� üũ ����" << std::endl;
	sort_.rebuild_bwt_miss();
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
	std::cout << "�ҿ�ð� " << end_time << "�� �Դϴ�." << std::endl;

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
	std::cout << (float)count / sort_.original_sequence_bwt.size() * 100 << "% ����ġ" << std::endl;
	std::cout << count_diff << "�� ����ġ" << std::endl;


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
	std::cout << (float)count2 / sort_.original_sequence_bwt.size() * 100 << "% ����ġ" << std::endl;
	std::cout << count_diff2 << "�� ����ġ" << std::endl;

	system("pause");
}