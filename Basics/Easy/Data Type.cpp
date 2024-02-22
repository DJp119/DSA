int dataTypes(string type) {
	if(type=="Integer") return 4;
	else if(type=="Long") return 8;
	else if(type=="Float") return 4;
	else if(type=="Double") return 8;
	else if(type=="Character") return 1;
	else return -1;
}
// swittch case 
int dataTypes(string type){
	char types = type[0];
	switch(types){
		case 'I' : return 4;
		case 'L' : return 8;
		case 'F' : return 4;
		case 'D' : return 8;
		case 'C' : return 1;
	}
}
https://www.codingninjas.com/studio/problems/data-type_8357232?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
