//Id : 2016112129 Name : taegun_kim

#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

void brutesearch(std::string test, std::string pattern) { 
	clock_t p_time; double end_time; int num = 0;
	p_time = clock();
	int index_num = 0; int times = 0; 
	for (int a = 0; a <= test.length()-pattern.length(); a++) {  //��Ƚ���� ����� ����ϱ� ���� for������ �񱳹��� �ٲ�
		//if (test.substr(a, pattern.length()).compare(pattern) == 0) { //case same string
		//	times++;
		//	//std::cout << a  << "��° ��ġ���� " << pattern << "�߰�" << std::endl;
		//}
		for (int b = 0; b < pattern.length(); b++) { //���� ���̸�ŭ ���� ���ڿ����� ���� �� ��
			num++;
			if (test[a + b] != pattern[b]) { //���߿� ���ڰ� �ٸ��� �ƿ�
				break;
			}
			else if (b == pattern.length() - 1) { //������ ���ؼ� ��ġ�ϴ� ���
				times++;
				std::cout << a << "��° ��ġ���� " << pattern << "�߰�" << std::endl;
			}
		}
	}
	std::cout << "�� " << times << "�� �߰�" << std::endl;
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
//	std::cout << "�����ð��� " << end_time << "�� �Դϴ�." << std::endl;
	std::cout << "�� ��Ƚ�� �� " << num << "�� �Դϴ�." << std::endl;
}
void rksearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time; int num = 0;
	p_time = clock();
	int index_num = 0; int times = 0; 
	int p_h = 0; int t_h = 0; int mod = 0;
	for (int i = 0; i < pattern.length(); i++) { //�ؽ� ���̺��� �̿��ϱ� ���� �ؽð� ���ϴ� �ڵ�
		p_h = p_h + (pattern[i] * pow(2, pattern.length()-(i+1))); //������ �ؽ���
		t_h = t_h + (test[i] * pow(2, pattern.length() - (i + 1))); //0��° ���ڿ��� �ؽ���
		mod = mod + ('z' * pow(2, pattern.length() - (i + 1)));  // mod���� 
	}
	mod = mod / 2; //mod���� �ʹ� Ŀ���°� ���� 
	p_h = p_h % mod;
	t_h = t_h % mod;
	for (int a = 0; a <= test.length() - pattern.length(); a++) {
		num++; //��尪 ���ϱ� ������ Ƚ������
		if (a == 0) {} //�ʱ� mod���� ���� �ֱ� ������ ����
		else {

			t_h = (int)(2 * t_h + (test[a + pattern.length() - 1] * 1 - (test[a - 1] * pow(2, pattern.length())))) % mod;
			if (t_h < 0) t_h = t_h + mod;
		}
		
		if (t_h == p_h) {
			//if (test.substr(a, pattern.length()).compare(pattern) == 0) {
			//	times++;
			////	
			//}
			for (int b = 0; b < pattern.length(); b++) {
				num++; //mod���� ������� ������ ������� �ϱ� ������ Ƚ�� ����
				if (test[a + b] != pattern[b]) {
					break;
				}
				else if (b == pattern.length() - 1) {
					times++;
					std::cout << a << "��° ��ġ���� " << pattern << "�߰�" << std::endl;
				}
			}
		}
	}
	std::cout << "�� " << times << "�� �߰�" << std::endl;
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
//	std::cout << "�ɸ��ð��� " << end_time << "�� �Դϴ�." << std::endl;
	std::cout << "�� ��Ƚ�� �� " << num << "�� �Դϴ�." << std::endl;
}

void sp(std::string pattern, int *array) {  //sp table �����Լ�
	array[0] = 0;
	int a, b;
	for (a = 1, b = 0; a < pattern.length(); a++) {
		while (b > 0 && pattern[a] != pattern[b]) {
			b = array[b - 1];
		}
		if (pattern[a] == pattern[b]) {

			array[a] = ++b ;
		}
	}
}

void kmpsearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time; int num = 0;
	p_time = clock();

	int times = 0; int a, b;
	int *find_pattern = new int[pattern.length()];  //sp array �� �����ϱ� ���� array  
	for (int i = 0; i < pattern.length(); i++) { //�ʱ�ȭ
		find_pattern[i] = 0;
	}
	sp(pattern, find_pattern); //sp table ����

	for (a = 0, b = 0; a < test.length(); a++) {
		num++;
		while (b > 0 && test[a] != pattern[b]) {
			b = find_pattern[b - 1]; //���� ��ġ�� �� ���� �������ϰ� ���ڰ� �ٸ���� ���ܰ�� ���ư���.
		}
		num++;
		if (test[a] == pattern[b]) { //���� ���ϰ� ���ڰ� �������
			num++;
			if (b == pattern.length() - 1) { //������ ���������ڿ������� ã�����
				times++;
				std::cout << a - pattern.length()+1 << "��° ��ġ���� "<< pattern << " �߰�" << std::endl;
				b = find_pattern[b];		
			}
			else {  //���� �ܰ�� �̵�
				b++;
			}
		}
	}
	std::cout << "�� " << times << "�� �߰�" << std::endl;
	delete[] find_pattern;

	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
//	std::cout << "�ɸ��ð��� " << end_time << "�� �Դϴ�." << std::endl;
	std::cout << "�� ��Ƚ�� �� " << num << "�� �Դϴ�." << std::endl;
}
int main() {

	std::string test_string = "A STRING SEARCHING EXAMPLE CONSISTING OF A GIVEN PATTERN STRING";
	std::string pattern_string = "STRING";
	//std::string test_string = "AAAAAA";
	//std::string pattern_string = "AAA";


	std::cout << "brutesearch" << std::endl;
	brutesearch(test_string, pattern_string);
	std::cout << std::endl;
	std::cout << "rksearch" << std::endl;
	rksearch(test_string, pattern_string);
	std::cout << std::endl;
	std::cout << "kmpsearch" << std::endl;
	kmpsearch(test_string, pattern_string);
	std::cout << std::endl;
	system("pause");
	return 0;

}