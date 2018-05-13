//Id : 2016112129 Name : taegun_kim

#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

void brutesearch(std::string test, std::string pattern) { 
	clock_t p_time; double end_time; int num = 0;
	p_time = clock();
	int index_num = 0; int times = 0; 
	for (int a = 0; a <= test.length()-pattern.length(); a++) {  //비교횟수를 제대로 출력하기 위해 for문으로 비교문을 바꿈
		//if (test.substr(a, pattern.length()).compare(pattern) == 0) { //case same string
		//	times++;
		//	//std::cout << a  << "번째 위치에서 " << pattern << "발견" << std::endl;
		//}
		for (int b = 0; b < pattern.length(); b++) { //패턴 길이만큼 현재 문자열부터 패턴 을 비교
			num++;
			if (test[a + b] != pattern[b]) { //도중에 문자가 다르면 아웃
				break;
			}
			else if (b == pattern.length() - 1) { //끝까지 비교해서 일치하는 경우
				times++;
				std::cout << a << "번째 위치에서 " << pattern << "발견" << std::endl;
			}
		}
	}
	std::cout << "총 " << times << "번 발견" << std::endl;
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
//	std::cout << "끝난시간은 " << end_time << "초 입니다." << std::endl;
	std::cout << "총 비교횟수 는 " << num << "번 입니다." << std::endl;
}
void rksearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time; int num = 0;
	p_time = clock();
	int index_num = 0; int times = 0; 
	int p_h = 0; int t_h = 0; int mod = 0;
	for (int i = 0; i < pattern.length(); i++) { //해쉬 테이블을 이용하기 위해 해시값 구하는 코드
		p_h = p_h + (pattern[i] * pow(2, pattern.length()-(i+1))); //패턴의 해쉬값
		t_h = t_h + (test[i] * pow(2, pattern.length() - (i + 1))); //0번째 문자열의 해쉬값
		mod = mod + ('z' * pow(2, pattern.length() - (i + 1)));  // mod변수 
	}
	mod = mod / 2; //mod값이 너무 커지는걸 방지 
	p_h = p_h % mod;
	t_h = t_h % mod;
	for (int a = 0; a <= test.length() - pattern.length(); a++) {
		num++; //모드값 비교하기 때문에 횟수증가
		if (a == 0) {} //초기 mod값은 위에 있기 때문에 구분
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
				num++; //mod값이 같은경우 일일히 비교해줘야 하기 때문에 횟수 증가
				if (test[a + b] != pattern[b]) {
					break;
				}
				else if (b == pattern.length() - 1) {
					times++;
					std::cout << a << "번째 위치에서 " << pattern << "발견" << std::endl;
				}
			}
		}
	}
	std::cout << "총 " << times << "번 발견" << std::endl;
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
//	std::cout << "걸린시간은 " << end_time << "초 입니다." << std::endl;
	std::cout << "총 비교횟수 는 " << num << "번 입니다." << std::endl;
}

void sp(std::string pattern, int *array) {  //sp table 생성함수
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
	int *find_pattern = new int[pattern.length()];  //sp array 값 저장하기 위한 array  
	for (int i = 0; i < pattern.length(); i++) { //초기화
		find_pattern[i] = 0;
	}
	sp(pattern, find_pattern); //sp table 생성

	for (a = 0, b = 0; a < test.length(); a++) {
		num++;
		while (b > 0 && test[a] != pattern[b]) {
			b = find_pattern[b - 1]; //현재 위치와 그 다음 예상패턴과 문자가 다를경우 전단계로 돌아간다.
		}
		num++;
		if (test[a] == pattern[b]) { //예상 패턴과 문자가 같은경우
			num++;
			if (b == pattern.length() - 1) { //패턴의 마지막문자였던경우는 찾은경우
				times++;
				std::cout << a - pattern.length()+1 << "번째 위치에서 "<< pattern << " 발견" << std::endl;
				b = find_pattern[b];		
			}
			else {  //다음 단계로 이동
				b++;
			}
		}
	}
	std::cout << "총 " << times << "번 발견" << std::endl;
	delete[] find_pattern;

	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
//	std::cout << "걸린시간은 " << end_time << "초 입니다." << std::endl;
	std::cout << "총 비교횟수 는 " << num << "번 입니다." << std::endl;
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