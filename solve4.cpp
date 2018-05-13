//Id : 2016112129 Name : taegun_kim

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>

void brutesearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time;
	p_time = clock();  //실행 시간을 측정하기 위해 함수가 실행될때 스타트
	std::ofstream out_f("br_output.txt"); //검색결과를 출력하기 위해 만든 ofstream 변수
	int times = 0; //총 몇번 찾았는지 체크하기 위해 만든 변수
	for (int a = 0; a <= test.length() - pattern.length(); a++) {  //한칸 한칸 이동하면서 pattern 문자열의 길이만큼씩 문자열을 비교하는 방식
		if (test.substr(a, pattern.length()).compare(pattern) == 0) { //pattern 과 일치하는 문자열을 찾은 경우
			times++;  //찾은 횟수를 한번 올리고
			out_f << a << "번째 위치에서 " << pattern << "발견" << std::endl; // output파일에 입력
		}
	}
	std::cout << "총 " << times << "번 발견" << std::endl;
	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC; // 총 작업시간 체크
	std::cout << "끝난시간은 " << end_time << "초 입니다." << std::endl; // 작업시간 출력
	out_f.close(); // 파일 닫기
}
void sp(std::string pattern, int *array) { //make sp table, array배열은 sp table의 값을 저장하기 위한 배열 
	array[0] = 0; //시작지점 
	int a, b; //for문, index로 사용하기 위한 변수
	for (a = 1, b = 0; a < pattern.length(); a++) { //첫번째 prefix table의 값은 0이기 때문에 a를 1부터 시작
		while (b > 0 && pattern[a] != pattern[b]) { //b는 배열에 들어갈 값이다, while문은 b가 0보다 클때 되기 때문에 아래 if문이 먼저 실행된다. 
			b = array[b - 1];						//앞의 prefix 문자열과 suffix 문자열의 값이 서로 다르게되면 그 전단계의 인덱스로 돌아간다. 
		}
		if (pattern[a] == pattern[b]) {  // 맨 처음 상태인 경우 a=1, b=0이므로 pattern의 첫번째와 두번째 문장이 같다는 뜻. 그럼 array[1] 에는 1의 값이 들어가게된다.
										 // 즉 앞뒤 문자가 같게 되면 sp array의 값이 하나씩 증가하면서 입력된다.

										 //처음 상태가 아닌 경우에는 위의 while문에서 그 전단계의 index number를 받아오고 그 위치의 값과 현재 a의 값이 같으면 b보다 1 더 큰 숫자를 입력
			array[a] = ++b;
		}
	}
}

void kmpsearch(std::string test, std::string pattern) {
	clock_t p_time; double end_time;
	p_time = clock(); //시작시간 check
	std::ofstream out_f("km_output.txt"); //출력결과를 저장할 위치

	int times = 0; int a, b; //for문과 index로 사용할 변수
	int *find_pattern = new int[pattern.length()]; //sp table 값을 저장할 array
	for (int i = 0; i < pattern.length(); i++) {
		find_pattern[i] = 0; //어레이 초기화
	}
	sp(pattern, find_pattern); //sp table 작성

	for (a = 0, b = 0; a < test.length(); a++) {
		while (b > 0 && test[a] != pattern[b]) {  //현재 위치의 문자와 pattern값을 비교
			b = find_pattern[b - 1]; //sp table값을 이용해 b의 값을 조정해서 pattern을 효율적으로 이용
		}

		if (test[a] == pattern[b]) { //현재 위치의 문자와 pattern의 sp table에 의한 위치의 값과 동일한 경우
			if (b == pattern.length() - 1) { //b가 pattern의 마지막 위치를 가리키고 있으면 현재 찾는 문자열을 찾은것이기 때문에
				times++; //찾은 횟수를 한번 증가시키고
				out_f << a - pattern.length() + 1 << "번째 위치에서 " << pattern << " 발견" << std::endl; //결과를 기록
				b = find_pattern[b]; //b의 위치를 이동 하는 이유는 찾은 문자열의 내부위치로부터 또 찾는 문자열이 나올 수 있기 때문이다. 
			}
			else {
				b++;  //다음 칸으로 이동해서 문자열을 비교한다.
			}
		}
	}
	std::cout << "총 " << times << "번 발견" << std::endl;
	delete[] find_pattern; //메모리 반납

	end_time = (double)(clock() - p_time) / CLOCKS_PER_SEC;
	std::cout << "걸린시간은 " << end_time << "초 입니다." << std::endl;
	out_f.close(); //파일 닫기
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
	std::cout << "생성완료" << std::endl;
	txt_file.close();
	std::ifstream in_f("input_solve4.txt"); // 분석할 input파일을 읽어오는 코드
	std::string test_string; // 코드를 받아올 String 변수
	std::string pattern_string = "GCGCAGCACTACCAAGATGAATATAATCTT";  // 찾을 pattern 문자열
	if (in_f.is_open()) {  //파일이 정상적으로 열렷는지 확인하는 코드
		getline(in_f, test_string); //파일이 한줄로 되어있기 때문에 한번만 읽는다.
	}
	else { //파일이 정상적으로 열리지 않는 경우 종료
		std::cout << "file open failed" << std::endl;
		return 0;
	}
	std::cout << "test_string 길이 :" << n << std::endl;
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