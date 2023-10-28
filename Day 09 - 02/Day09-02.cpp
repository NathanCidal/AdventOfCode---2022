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
	int lastX[ropeSize];
	int lastY[ropeSize];

	for(int i = 0; i < ropeSize; i++){
		lastX[i] = x;
		lastY[i] = y;
	}

 int distX;
 int distY;
	char test = '0';

	map[lastY[ropeSize-1]][lastX[ropeSize-1]] = 'S';

	while(true){
		cout << "> Trabalhando" << endl;
		cin >> direction;
		if(direction == '.') break;

		if(direction == 'R'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(x + 1 > lastX[0] + 1){
					lastX[0] = x;
					lastY[0] = y;
				}

				for(int i = 1; i < ropeSize; i++){
					distX = lastX[i] - lastX[i-1];	
					distY = lastY[i] - lastY[i-1];

					if(distX < 0) distX *= -1;
					if(distY < 0) distY *= -1;

					if(distX > 1 || distY > 1){
						if(lastX[i] < lastX[i-1])
						 	lastX[i]++;

						if(lastX[i] > lastX[i-1])
							lastX[i]--;

						if(lastY[i] < lastY[i-1])
							lastY[i]++;

						if(lastY[i] > lastY[i-1])
							lastY[i]--;
					}	
				}

				/*for(int i = 0; i < ropeSize; i++){
					cout << "Rope[" << i << "] - X: " << lastX[i] << " - Y:" << lastY[i] << endl;
				}
				cout << endl;*/		

				map[lastY[ropeSize-1]][lastX[ropeSize-1]] = '#';
				x++;
			}
		}

		if(direction == 'L'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(x - 1 < lastX[0] - 1){
					lastX[0] = x;
					lastY[0] = y;
				}

				for(int i = 1; i < ropeSize; i++){
					distX = lastX[i] - lastX[i-1];	
					distY = lastY[i] - lastY[i-1];

					if(distX < 0) distX *= -1;
					if(distY < 0) distY *= -1;

					if(distX > 1 || distY > 1){
						if(lastX[i] < lastX[i-1])
						 	lastX[i]++;

						if(lastX[i] > lastX[i-1])
							lastX[i]--;

						if(lastY[i] < lastY[i-1])
							lastY[i]++;

						if(lastY[i] > lastY[i-1])
							lastY[i]--;
					}	
				}

				/*for(int i = 0; i < ropeSize; i++){
					cout << "Rope[" << i << "] - X: " << lastX[i] << " - Y:" << lastY[i] << endl;
				}
				cout << endl;*/


				map[lastY[ropeSize-1]][lastX[ropeSize-1]] = '#';	
				x--;	
			}
		}

		if(direction == 'U'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(y - 1< lastY[0] - 1){
					lastX[0] = x;
					lastY[0] = y;
				}

				for(int i = 1; i < ropeSize; i++){
					distX = lastX[i] - lastX[i-1];	
					distY = lastY[i] - lastY[i-1];

					if(distX < 0) distX *= -1;
					if(distY < 0) distY *= -1;

					if(distX > 1 || distY > 1){
						if(lastX[i] < lastX[i-1])
						 	lastX[i]++;

						if(lastX[i] > lastX[i-1])
							lastX[i]--;
					
						if(lastY[i] < lastY[i-1])
							lastY[i]++;

						if(lastY[i] > lastY[i-1])
							lastY[i]--;
					}
				}

				/*for(int i = 0; i < ropeSize; i++){
					cout << "Rope[" << i << "] - X: " << lastX[i] << " - Y:" << lastY[i] << endl;
				}

				cout << endl;*/
				map[lastY[ropeSize-1]][lastX[ropeSize-1]] = '#';
				y--;
			}
		}

		if(direction == 'D'){
			cin >> numMov;

			for(int i = 0; i < numMov; i++){
				if(y + 1 > lastY[0] + 1){
					lastX[0] = x;
					lastY[0] = y;
				}

				for(int i = 1; i < ropeSize; i++){
					distX = lastX[i] - lastX[i-1];	
					distY = lastY[i] - lastY[i-1];

					if(distX < 0) distX *= -1;
					if(distY < 0) distY *= -1;


					if(distX > 1 || distY > 1){
						if(lastX[i] < lastX[i-1])
						 	lastX[i]++;

						if(lastX[i] > lastX[i-1])
							lastX[i]--;
					
						if(lastY[i] < lastY[i-1])
							lastY[i]++;

						if(lastY[i] > lastY[i-1])
							lastY[i]--;
					}
				}

				/*for(int i = 0; i < ropeSize; i++){
					cout << "Rope[" << i << "] - X: " << lastX[i] << " - Y:" << lastY[i] << endl;
				}
				cout << endl;*/

				map[lastY[ropeSize-1]][lastX[ropeSize-1]] = '#';	
				y++;
			}
		}

		/*for(int i = 0; i < sizeY; i++){
			for(int j = 0; j < sizeX; j++){
				cout << map[i][j];
			}
			cout << endl;
		}*/
	}

	int contador = 0;
	for(int i = 0; i < sizeY; i++){
		for(int j = 0; j < sizeX; j++){
			if(map[i][j] == '#') contador++;
		}
	}

	map[sizeY/2][(sizeX/2)] = 'S';

	cout << endl << "Sum: " << contador << endl;

	for(int i = 0; i < sizeY; i++){
		delete map[i];
	}
	delete[] map;

	return 0;
}