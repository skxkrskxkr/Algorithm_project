//Id : 2016112129 Name : taegun_kim

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>

void brutesearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time;
	p_time = clock();  //���� �ð��� �����ϱ� ���� �Լ��� ����ɶ� ��ŸƮ
	std::ofstream out_f("br_output.txt"); //�˻������ ����ϱ� ���� ���� ofstream ����
	int times = 0; //�� ��� ã�Ҵ��� üũ�ϱ� ���� ���� ����
	for (int a = 0; a <= test.length() - pattern.length(); a++) {  //��ĭ ��ĭ �̵��ϸ鼭 pattern ���ڿ��� ���̸�ŭ�� ���ڿ��� ���ϴ� ���
		if (test.substr(a, pattern.length()).compare(pattern) == 0) { //pattern �� ��ġ�ϴ� ���ڿ��� ã�� ���
			times++;  //ã�� Ƚ���� �ѹ� �ø���
			out_f << a << "��° ��ġ���� " << pattern << "�߰�" << std::endl; // output���Ͽ� �Է�
		}
	}
	std::cout << "�� " << times << "�� �߰�" << std::endl;
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC; // �� �۾��ð� üũ
	std::cout << "�����ð��� " << end_time << "�� �Դϴ�." << std::endl; // �۾��ð� ���
	out_f.close(); // ���� �ݱ�
}
void sp(std::string pattern, int *array) { //make sp table, array�迭�� sp table�� ���� �����ϱ� ���� �迭 
	array[0] = 0; //�������� 
	int a, b; //for��, index�� ����ϱ� ���� ����
	for (a = 1, b = 0; a < pattern.length(); a++) { //ù��° prefix table�� ���� 0�̱� ������ a�� 1���� ����
		while (b > 0 && pattern[a] != pattern[b]) { //b�� �迭�� �� ���̴�, while���� b�� 0���� Ŭ�� �Ǳ� ������ �Ʒ� if���� ���� ����ȴ�. 
			b = array[b - 1];						//���� prefix ���ڿ��� suffix ���ڿ��� ���� ���� �ٸ��ԵǸ� �� ���ܰ��� �ε����� ���ư���. 
		}
		if (pattern[a] == pattern[b]) {  // �� ó�� ������ ��� a=1, b=0�̹Ƿ� pattern�� ù��°�� �ι�° ������ ���ٴ� ��. �׷� array[1] ���� 1�� ���� ���Եȴ�.
										 // �� �յ� ���ڰ� ���� �Ǹ� sp array�� ���� �ϳ��� �����ϸ鼭 �Էµȴ�.

										 //ó�� ���°� �ƴ� ��쿡�� ���� while������ �� ���ܰ��� index number�� �޾ƿ��� �� ��ġ�� ���� ���� a�� ���� ������ b���� 1 �� ū ���ڸ� �Է�
			array[a] = ++b;
		}
	}
}

void kmpsearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time;
	p_time = clock(); //���۽ð� check
	std::ofstream out_f("km_output.txt"); //��°���� ������ ��ġ

	int times = 0; int a, b; //for���� index�� ����� ����
	int *find_pattern = new int[pattern.length()]; //sp table ���� ������ array
	for (int i = 0; i < pattern.length(); i++) {
		find_pattern[i] = 0; //��� �ʱ�ȭ
	}
	sp(pattern, find_pattern); //sp table �ۼ�

	for (a = 0, b = 0; a < test.length(); a++) {
		while (b > 0 && test[a] != pattern[b]) {  //���� ��ġ�� ���ڿ� pattern���� ��
			b = find_pattern[b - 1]; //sp table���� �̿��� b�� ���� �����ؼ� pattern�� ȿ�������� �̿�
		}

		if (test[a] == pattern[b]) { //���� ��ġ�� ���ڿ� pattern�� sp table�� ���� ��ġ�� ���� ������ ���
			if (b == pattern.length() - 1) { //b�� pattern�� ������ ��ġ�� ����Ű�� ������ ���� ã�� ���ڿ��� ã�����̱� ������
				times++; //ã�� Ƚ���� �ѹ� ������Ű��
				out_f << a - pattern.length() + 1 << "��° ��ġ���� " << pattern << " �߰�" << std::endl; //����� ���
				b = find_pattern[b]; //b�� ��ġ�� �̵� �ϴ� ������ ã�� ���ڿ��� ������ġ�κ��� �� ã�� ���ڿ��� ���� �� �ֱ� �����̴�. 
			}
			else {
				b++;  //���� ĭ���� �̵��ؼ� ���ڿ��� ���Ѵ�.
			}
		}
	}
	std::cout << "�� " << times << "�� �߰�" << std::endl;
	delete[] find_pattern; //�޸� �ݳ�

	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
	std::cout << "�ɸ��ð��� " << end_time << "�� �Դϴ�." << std::endl;
	out_f.close(); //���� �ݱ�
}
//Id : 2016112129 Name : taegun_kim
int main()
{
	int n = 100000000;
	srand((unsigned int)time(NULL));
	std::ofstream txt_file("input_solve4.txt");
	for (int i = 0; i < n; i++) {

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
	std::cout << "�����Ϸ�" << std::endl;
	txt_file.close();
	std::ifstream in_f("input_solve4.txt"); // �м��� input������ �о���� �ڵ�
	std::string test_string; // �ڵ带 �޾ƿ� String ����
	std::string pattern_string = "GCGCAGCACTACCAAGATGAATATAATCTT";  // ã�� pattern ���ڿ�
	if (in_f.is_open()) {  //������ ���������� ���Ǵ��� Ȯ���ϴ� �ڵ�
		getline(in_f, test_string); //������ ���ٷ� �Ǿ��ֱ� ������ �ѹ��� �д´�.
	}
	else { //������ ���������� ������ �ʴ� ��� ����
		std::cout << "file open failed" << std::endl;
		return 0;
	}
	std::cout << "test_string ���� :" << n << std::endl;
	std::cout << "pattern_string :" << pattern_string << std::endl;
	std::cout << std::endl;

	std::cout << "brutesearch" << std::endl;
	brutesearch(test_string, pattern_string);
	std::cout << std::endl;

	std::cout << "kmpsearch" << std::endl;
	kmpsearch(test_string, pattern_string);
	std::cout << std::endl;

	in_f.close();
	system("pause");
	return 0;
}