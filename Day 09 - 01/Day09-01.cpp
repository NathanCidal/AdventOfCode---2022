#include <iostream>
#include <string>

using namespace std;

int main(){
	int jaVisitados = 0;
	
	char direction;
	int numMov;

	int sizeX = 1000;
	int sizeY = 1000;
	
	char ** map = new char*[sizeY];
	for(int i = 0; i < sizeY; i++){
		map[i] = new char[sizeX];
	}

	for(int i = 0; i < sizeY; i++){
		for(int j = 0; j < sizeX; j++){
			map[i][j] = '.';
		}
	}

	int x = sizeX / 2;
	int y = sizeY / 2;

	int ropeSize = 9;
	int lastX = x - 1;
	int lastY = y;

	map[lastY][lastX] = '#';

	while(true){
		//cout << "> Trabalhando" << endl;
		cin >> direction;
		if(direction == '.') break;

		if(direction == 'R'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(x + 1 > lastX + 1){
					lastX = x;
					lastY = y;
				}
				map[lastY][lastX] = '#';
				x++;
			}
		}

		if(direction == 'L'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(x - 1 < lastX - 1){
					lastX = x;
					lastY = y;
				}

				map[lastY][lastX] = '#';			
				
				x--;
			}
		}

		if(direction == 'U'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(y - 1 < lastY - 1){
					lastX = x;
					lastY = y;
				}

				map[lastY][lastX] = '#';
				y--;
			}
		}

		if(direction == 'D'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(y + 1 > lastY + 1){
					lastX = x;
					lastY = y;
				}
				
				map[lastY][lastX] = '#';
				y++;
			}
		}
	}

	int contador = 0;
	for(int i = 0; i < sizeY; i++){
		for(int j = 0; j < sizeX; j++){
			if(map[i][j] == '#') contador++;
		}
	}

	map[sizeY/2][(sizeX/2)] = 'S';

	/*for(int i = 0; i < sizeY; i++){
		for(int j = 0; j < sizeX; j++){
			cout << map[i][j];
		}
		cout << endl;
	}*/

	cout << endl << "Sum: " << contador << endl;

	for(int i = 0; i < sizeY; i++){
		delete map[i];
	}
	delete[] map;

	

	return 0;
}