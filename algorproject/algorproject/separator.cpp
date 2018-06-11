#include "separator.h"
#include <iostream>
#include <fstream>
#include <string>


void separator::make(std::string abc) {
	int ar_temp;
	//	std::ofstream bwt_pre_sort_aa("bwt_pre_sort_aa.txt"); std::ofstream bwt_pre_sort_ac("bwt_pre_sort_ac.txt");	std::ofstream bwt_pre_sort_ag("bwt_pre_sort_ag.txt");std::ofstream bwt_pre_sort_at("bwt_pre_sort_at.txt");
	//	std::ofstream bwt_pre_sort_ca("bwt_pre_sort_ca.txt"); std::ofstream bwt_pre_sort_cc("bwt_pre_sort_cc.txt");	std::ofstream bwt_pre_sort_cg("bwt_pre_sort_cg.txt"); std::ofstream bwt_pre_sort_ct("bwt_pre_sort_ct.txt");
	//	std::ofstream bwt_pre_sort_ga("bwt_pre_sort_ga.txt"); std::ofstream bwt_pre_sort_gc("bwt_pre_sort_gc.txt");	std::ofstream bwt_pre_sort_gg("bwt_pre_sort_gg.txt"); std::ofstream bwt_pre_sort_gt("bwt_pre_sort_gt.txt");
	//	std::ofstream bwt_pre_sort_ta("bwt_pre_sort_ta.txt"); std::ofstream bwt_pre_sort_tc("bwt_pre_sort_tc.txt");	std::ofstream bwt_pre_sort_tg("bwt_pre_sort_tg.txt"); std::ofstream bwt_pre_sort_tt("bwt_pre_sort_tt.txt");
		
	//for (int i = 0; i < abc.length(); i++) {
	//	if (i == 0) {
	//		bwt_pre_sort_aa << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
	//	}
	//	else if (abc.substr(abc.length() - 1 - i)[0] == 'A' && abc.substr(abc.length() - 1 - i)[1] == '$') {
	//		bwt_pre_sort_aa << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
	//	}
	//	else if (abc.substr(abc.length() - 1 - i)[0] == 'A' && abc.substr(abc.length() - 1 - i)[1] == 'A') {
	//		if (i == abc.length() - 1) {
	//			bwt_pre_sort_aa << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

	//		}
	//		else {
	//			bwt_pre_sort_aa << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
	//		}
	//	}
	//	else if (abc.substr(abc.length() - 1 - i)[0] == 'A' && abc.substr(abc.length() - 1 - i)[1] == 'C') {
	//		if (i == abc.length() - 1) {
	//			bwt_pre_sort_ac << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

	//		}
	//		else {
	//			bwt_pre_sort_ac << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
	//		}
	//	}
	//	else if (abc.substr(abc.length() - 1 - i)[0] == 'A' && abc.substr(abc.length() - 1 - i)[1] == 'G') {
	//		if (i == abc.length() - 1) {
	//			bwt_pre_sort_ag << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

	//		}
	//		else {
	//			bwt_pre_sort_ag << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
	//		}
	//	}
	//	else if (abc.substr(abc.length() - 1 - i)[0] == 'A' && abc.substr(abc.length() - 1 - i)[1] == 'T') {
	//		if (i == abc.length() - 1) {
	//			bwt_pre_sort_at << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

	//		}
	//		else {
	//			bwt_pre_sort_at << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
	//		}
	//	}
	/*	else if (abc.substr(abc.length() - 1 - i)[0] == 'C' && abc.substr(abc.length() - 1 - i)[1] == '$') {
			bwt_pre_sort_ca << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'C' && abc.substr(abc.length() - 1 - i)[1] == 'A') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_ca << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_ca << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'C' && abc.substr(abc.length() - 1 - i)[1] == 'C') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_cc << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_cc << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'C' && abc.substr(abc.length() - 1 - i)[1] == 'G') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_cg << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_cg << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'C' && abc.substr(abc.length() - 1 - i)[1] == 'T') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_ct << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_ct << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}*/
	/*	else if (abc.substr(abc.length() - 1 - i)[0] == 'G' && abc.substr(abc.length() - 1 - i)[1] == '$') {
			bwt_pre_sort_ga << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'G' && abc.substr(abc.length() - 1 - i)[1] == 'A') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_ga << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_ga << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'G' && abc.substr(abc.length() - 1 - i)[1] == 'C') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_gc << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_gc << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'G' && abc.substr(abc.length() - 1 - i)[1] == 'G') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_gg << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_gg << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}
		else if (abc.substr(abc.length() - 1 - i)[0] == 'G' && abc.substr(abc.length() - 1 - i)[1] == 'T') {
			if (i == abc.length() - 1) {
				bwt_pre_sort_gt << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

			}
			else {
				bwt_pre_sort_gt << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
			}
		}*/
		//else if (abc.substr(abc.length() - 1 - i)[0] == 'T' && abc.substr(abc.length() - 1 - i)[1] == '$') {
		//	bwt_pre_sort_ta << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		//}
		//else if (abc.substr(abc.length() - 1 - i)[0] == 'T' && abc.substr(abc.length() - 1 - i)[1] == 'A') {
		//	if (i == abc.length() - 1) {
		//		bwt_pre_sort_ta << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

		//	}
		//	else {
		//		bwt_pre_sort_ta << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		//	}
		//}
		//else if (abc.substr(abc.length() - 1 - i)[0] == 'T' && abc.substr(abc.length() - 1 - i)[1] == 'C') {
		//	if (i == abc.length() - 1) {
		//		bwt_pre_sort_tc << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

		//	}
		//	else {
		//		bwt_pre_sort_tc << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		//	}
		//}
		//else if (abc.substr(abc.length() - 1 - i)[0] == 'T' && abc.substr(abc.length() - 1 - i)[1] == 'G') {
		//	if (i == abc.length() - 1) {
		//		bwt_pre_sort_tg << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

		//	}
		//	else {
		//		bwt_pre_sort_tg << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		//	}
		//}
		//else if (abc.substr(abc.length() - 1 - i)[0] == 'T' && abc.substr(abc.length() - 1 - i)[1] == 'T') {
		//	if (i == abc.length() - 1) {
		//		bwt_pre_sort_tt << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << '$' << '\n';

		//	}
		//	else {
		//		bwt_pre_sort_tt << i << " " << abc.substr(abc.length() - 1 - i).substr(0, 60) << " " << abc.substr(0, abc.length() - 1 - i).substr(abc.substr(0, abc.length() - 1 - i).size() - 1, abc.substr(0, abc.length() - 1 - i).size())[0] << '\n';
		//	}
		//}
	//	std::cout << i << std::endl;
	//}
	

	//std::cout << "생성 종료" << std::endl;
	//	bwt_pre_sort_aa.close(); bwt_pre_sort_ac.close(); bwt_pre_sort_ag.close(); bwt_pre_sort_at.close();
	//	bwt_pre_sort_ca.close(); bwt_pre_sort_cc.close(); bwt_pre_sort_cg.close(); bwt_pre_sort_ct.close();
	//	bwt_pre_sort_ga.close(); bwt_pre_sort_gc.close(); bwt_pre_sort_gg.close(); bwt_pre_sort_gt.close();
	//	bwt_pre_sort_ta.close(); bwt_pre_sort_tc.close(); bwt_pre_sort_tg.close(); bwt_pre_sort_tt.close();
}