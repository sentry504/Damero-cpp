#include <iostream>
#include <limits>

using namespace std;

string jugador1, jugador2;
    int turno=1, x1, x2, y1, y2, izquierda_derecha, arriba_abajo, moverCasillas;
    int conteoNegras=12, conteoBlancas=12, opcion=0, piezas, esNumero;
   	bool negras=false, blancas=true, ficha=false, corona=false, puedeMover=false;
	string casillaFicha, casillaMover;
	
	string matriz_Tablero[8][8]={{"| - ","| N |"," - ","| N |"," - ","| N |"," - ","| N |"},
								 {"| N |"," - ","| N |"," - ","| N |"," - ","| N |"," - |"},
								 {"| - ","| N |"," - ","| N |"," - ","| N |"," - ","| N |"},
								 {"|   |"," - ","|   |"," - ","|   |"," - ","|   |"," - |"},
								 {"| - ","|   |"," - ","|   |"," - ","|   |"," - ","|   |"},
								 {"| B |"," - ","| B |"," - ","| B |"," - ","| B |"," - |"},
								 {"| - ","| B |"," - ","| B |"," - ","| B |"," - ","| B |"},
								 {"| B |"," - ","| B |"," - ","| B |"," - ","| B |"," - |"}};

void encabezado(string j1, string j2){
	std::cout << "\t---Juego de damas 8x8---" << std::endl;
	std::cout << "Jugador1: Blancas\tJugador2: Negras\n" << std::endl;
	std::cout << "Nombre de los jugadores:" << std::endl;
	std::cout << "Jugador 1: "<< j1 << "\tFichas blancas: "<< conteoBlancas << std::endl;
	std::cout << "Jugador 2: "<< j2 << "\tFichas negras: "<< conteoNegras << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}
								 
void cargaTablero(string matriz[8][8]){
    cout << "    0   1   2   3   4   5   6   7\n";
	for	(int i=0; i<8; i++){
		cout << i << " ";
		for	(int j=0; j<8; j++){
			cout<< matriz[i][j];
		}
		cout << "\n  ---------------------------------\n";
	}
}

int validacionEntrada(string mensaje, int dato){
	while (true) {
    	cout << mensaje;
    	if (cin >> dato) {
    	    break;
    	} else {
            cout << "Ingrese un valor valido!\n";
    	    cin.clear();
    		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    	}
    }
    return dato;
}

bool comprobacion(int x_, int y_, string control_, string control2_){
	if(!(x_>=0&&x_<8) || !(y_>=0&&y_<8) || (matriz_Tablero[x_][y_]==control_) || (matriz_Tablero[x_][y_]==control2_)){
		system("cls");
	    encabezado(jugador1,jugador2);
	    cargaTablero(matriz_Tablero);
		std::cout << "Posicion de ficha no encontrada..." << std::endl;
	    system("pause");
		system("cls");
		encabezado(jugador1,jugador2);
	    cargaTablero(matriz_Tablero);
	    return true;
	}
	
	if((matriz_Tablero[x_][y_]==" - ") || (matriz_Tablero[x_][y_]=="| - ") || (matriz_Tablero[x_][y_]==" - |") || (matriz_Tablero[x_][y_]=="|   |")){
		std::cout << "Posicion ilegal..." << std::endl;
		system("pause");
		system("cls");
	    encabezado(jugador1,jugador2);
		cargaTablero(matriz_Tablero);
	    return true;
	}
}

void cargaPrevia(){
	system("cls");
	encabezado(jugador1,jugador2);
	cargaTablero(matriz_Tablero);
	if(blancas){
		std::cout << "Turno de las blancas (" << jugador1 << ")" << std::endl;
	}
	if(negras){
	    std::cout << "Turno de las negras (" << jugador2 << ")" << std::endl;
	}
	std::cout << "Ficha seleccionada " << x1 << "x" << y1 << std::endl;
	izquierda_derecha= validacionEntrada("Mover ficha: izquierda(1)/derecha(2) ", izquierda_derecha);
}

bool movimiento(int x1_, int y1_, int x2_, int y2_){
	if((x2_>=0&&x2_<8) && (y2_>=0&&y2_<8) && matriz_Tablero[x2_][y2_]=="|   |"){
		casillaMover= matriz_Tablero[x2_][y2_];
		
		if(blancas){
			if(x2==0 && (y2_>=0&&y2_<8)){
				system("cls");
			    encabezado(jugador1,jugador2);
	    		cargaTablero(matriz_Tablero);
	    		std::cout << "!HAS HECHO UNA CORONA...! " << std::endl;
			    system("pause");
				casillaMover="|CN |";
			}	
		}
		if(negras){
			if(x2==7 && (y2_>=0&&y2_<8)){
				system("cls");
			    encabezado(jugador1,jugador2);
	    		cargaTablero(matriz_Tablero);
	    		std::cout << "!HAS HECHO UNA CORONA...! " << std::endl;
			    system("pause");
				casillaMover="|CB |";
			}	
		}
		
		matriz_Tablero[x1_][y1_]= casillaMover;
		matriz_Tablero[x2_][y2_]= casillaFicha;
		system("cls");
	    encabezado(jugador1,jugador2);
	    cargaTablero(matriz_Tablero);
		std::cout << "Ficha " << x1 << "x" << y1 << " movida a " << x2 << "x" << y2 << std::endl;
	    system("pause");
		system("cls");
		encabezado(jugador1,jugador2);
	    cargaTablero(matriz_Tablero);
	    return false;
	}else{
		system("cls");
	    encabezado(jugador1,jugador2);
	    cargaTablero(matriz_Tablero);
		std::cout << "Movimiento no permitido" << std::endl;
	    system("pause");
		system("cls");
		encabezado(jugador1,jugador2);
	    cargaTablero(matriz_Tablero);
	    return true;
	}
}

int main(){
	system("title Juego de Damero - Proyecto Programacion III");
	system("mode con: cols=50 lines=35");
	system("color F0");
	std::cout << "\t---Juego de damas 8x8---" << std::endl;
	std::cout << "Jugador1: Blancas\tJugador2: Negras\n" << std::endl;
	std::cout << "Nombre de los jugadores:" << std::endl;
	std::cout << "Jugador 1: ";
	std::cin >> jugador1;
	std::cout << "Jugador 2: ";
	std::cin >> jugador2;
	std::cout << "----------------------------------------" << std::endl;
	cargaTablero(matriz_Tablero);
	
	do{
		//comprobacion que la pieza seleccionada es correcta segun el turno
		do{
			if(blancas){
				ficha=false;
				std::cout << "Turno de las blancas (" << jugador1 << ")" << std::endl;
				std::cout << "Seleccionar ficha" << std::endl;
				x1= validacionEntrada("x: ", x1);
    			y1= validacionEntrada("y: ", y1);
    			
				ficha= comprobacion(x1,y1,"| N |", "|CN |");
				casillaFicha= matriz_Tablero[x1][y1];
				if (casillaFicha=="|CB |"){
					corona=true;
				}else{
					corona=false;
				}
			}
			if(negras){
				ficha=false;
				std::cout << "Turno de las negras (" << jugador2 << ")" << std::endl;
				std::cout << "Seleccionar ficha" << std::endl;
				x1= validacionEntrada("x: ", x1);
    			y1= validacionEntrada("y: ", y1);
    			
				ficha= comprobacion(x1,y1,"| B |", "|CB |");
				casillaFicha= matriz_Tablero[x1][y1];
				if (casillaFicha=="|CN |"){
					corona=true;
				}else{
					corona=false;
				}
			}
		}while(ficha);
		
		//comprobacion si la pieza es una corona para determinar los movimientos disponibles
		do{
	    	if (corona){
	    		cargaPrevia();
    			if(blancas){
		    		switch(izquierda_derecha){
			    		case 1:
			    			arriba_abajo= validacionEntrada("Mover ficha: arriba(1)/abajo(2) ", arriba_abajo);
			    			switch (arriba_abajo){
			    				case 1: //Izquierda arriba
				    				moverCasillas= validacionEntrada("N0. casillas a desplazarse ", moverCasillas);
				    				
				    				if(((x1-moverCasillas)>=0 && (x1-moverCasillas)<8) && ((y1-moverCasillas)>=0 && (y1-moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1-moverCasillas;
									    		y2=y1-moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= 1; i<moverCasillas; i++){
													if ((matriz_Tablero[x1-i][y1-i]=="| N |") || (matriz_Tablero[x1-i][y1-i]=="|CN |") || (matriz_Tablero[x1-i][y1-i]=="|B |") || (matriz_Tablero[x1-i][y1-i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1-(moverCasillas-1)][y1-(moverCasillas-1)]=="| N |") || (matriz_Tablero[x1-(moverCasillas-1)][y1-(moverCasillas-1)]=="|CN |")){
					    								x2=x1-moverCasillas;
							    						y2=y1-moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1-(moverCasillas-1)][y1-(moverCasillas-1)]="|   |";
							    							conteoNegras-=1;
														}
							    						cout << "\nFicha [" << x1-(moverCasillas-1) << "][" << y1-(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								case 2: //Izquierda abajo
									moverCasillas= validacionEntrada("N0. casillas a desplazarse ", moverCasillas);
									
									if(((x1+moverCasillas)>=0 && (x1+moverCasillas)<8) && ((y1-moverCasillas)>=0 && (y1-moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1+moverCasillas;
									    		y2=y1-moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1+i][y1-i]=="| N |") || (matriz_Tablero[x1+i][y1-i]=="|CN |") || (matriz_Tablero[x1+i][y1-i]=="|B |") || (matriz_Tablero[x1+i][y1-i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1+(moverCasillas-1)][y1-(moverCasillas-1)]=="| N |") || (matriz_Tablero[x1+(moverCasillas-1)][y1-(moverCasillas-1)]=="|CN |")){
					    								x2=x1+moverCasillas;
							    						y2=y1-moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1+(moverCasillas-1)][y1-(moverCasillas-1)]="|   |";
							    							conteoNegras-=1;
														}
							    						cout << "\nFicha [" << x1+(moverCasillas-1) << "][" << y1-(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								default:
									break;
							}
							break;
		    			case 2:
		    				arriba_abajo= validacionEntrada("Mover ficha: arriba(1)/abajo(2) ", arriba_abajo);
		    				switch (arriba_abajo){
			    				case 1: //Derecha arriba
			    					std::cout << "N0. casillas a desplazarse ";
				    				std::cin >> moverCasillas;
				    				if(((x1-moverCasillas)>=0 && (x1-moverCasillas)<8) && ((y1+moverCasillas)>=0 && (y1+moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1-moverCasillas;
									    		y2=y1+moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1-i][y1+i]=="| N |") || (matriz_Tablero[x1-i][y1+i]=="|CN |") || (matriz_Tablero[x1-i][y1+i]=="|B |") || (matriz_Tablero[x1-i][y1+i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1-(moverCasillas-1)][y1+(moverCasillas-1)]=="| N |") || (matriz_Tablero[x1-(moverCasillas-1)][y1+(moverCasillas-1)]=="|CN |")){
					    								x2=x1-moverCasillas;
							    						y2=y1+moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1-(moverCasillas-1)][y1+(moverCasillas-1)]="|   |";
							    							conteoNegras-=1;
														}
							    						cout << "\nFicha [" << x1-(moverCasillas-1) << "][" << y1+(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								case 2: //Derecha abajo
									std::cout << "N0. casillas a desplazarse ";
				    				std::cin >> moverCasillas;
				    				if(((x1+moverCasillas)>=0 && (x1+moverCasillas)<8) && ((y1+moverCasillas)>=0 && (y1+moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1+moverCasillas;
									    		y2=y1+moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1+i][y1+i]=="| N |") || (matriz_Tablero[x1+i][y1+i]=="|CN |") || (matriz_Tablero[x1+i][y1+i]=="|B |") || (matriz_Tablero[x1+i][y1+i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1+(moverCasillas-1)][y1+(moverCasillas-1)]=="| N |") || (matriz_Tablero[x1+(moverCasillas-1)][y1+(moverCasillas-1)]=="|CN |")){
					    								x2=x1+moverCasillas;
							    						y2=y1+moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1+(moverCasillas-1)][y1+(moverCasillas-1)]="|   |";
							    							conteoNegras-=1;
														}
							    						cout << "\nFicha [" << x1+(moverCasillas-1) << "][" << y1+(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								default:
									break;
							}
							break;
				    	default:
		    				cout << "Opcion no valida";
		    				break;
					}
				} 
				if(negras){
		    		switch(izquierda_derecha){
			    		case 1:
			    			arriba_abajo= validacionEntrada("Mover ficha: arriba(1)/abajo(2) ", arriba_abajo);
			    			switch (arriba_abajo){
			    				case 1: //Izquierda arriba
			    					moverCasillas= validacionEntrada("N0. casillas a desplazarse ", moverCasillas);
				    				if(((x1-moverCasillas)>=0 && (x1-moverCasillas)<8) && ((y1-moverCasillas)>=0 && (y1-moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1-moverCasillas;
									    		y2=y1-moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1-i][y1-i]=="| B |") || (matriz_Tablero[x1-i][y1-i]=="|CB |") || (matriz_Tablero[x1-i][y1-i]=="| N |") || (matriz_Tablero[x1-i][y1-i]=="|CN |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1-(moverCasillas-1)][y1-(moverCasillas-1)]=="| B |") || (matriz_Tablero[x1-(moverCasillas-1)][y1-(moverCasillas-1)]=="|CB |")){
					    								x2=x1-moverCasillas;
							    						y2=y1-moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1-(moverCasillas-1)][y1-(moverCasillas-1)]="|   |";
							    							conteoBlancas-=1;
														}
							    						cout << "\nFicha [" << x1-(moverCasillas-1) << "][" << y1-(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								case 2: //Izquierda abajo
									std::cout << "N0. casillas a desplazarse ";
				    				std::cin >> moverCasillas;
				    				if(((x1+moverCasillas)>=0 && (x1+moverCasillas)<8) && ((y1-moverCasillas)>=0 && (y1-moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1+moverCasillas;
									    		y2=y1-moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1+i][y1-i]=="| N |") || (matriz_Tablero[x1+i][y1-i]=="|CN |") || (matriz_Tablero[x1+i][y1-i]=="|B |") || (matriz_Tablero[x1+i][y1-i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1+(moverCasillas-1)][y1-(moverCasillas-1)]=="| B |") || (matriz_Tablero[x1+(moverCasillas-1)][y1-(moverCasillas-1)]=="|CB |")){
					    								x2=x1+moverCasillas;
							    						y2=y1-moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1+(moverCasillas-1)][y1-(moverCasillas-1)]="|   |";
							    							conteoBlancas-=1;
														}
							    						cout << "\nFicha [" << x1+(moverCasillas-1) << "][" << y1-(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								default:
									break;
							}
							break;
		    			case 2:
		    				arriba_abajo= validacionEntrada("Mover ficha: arriba(1)/abajo(2) ", arriba_abajo);
		    				switch (arriba_abajo){
			    				case 1: //Derecha arriba
			    					std::cout << "N0. casillas a desplazarse ";
				    				std::cin >> moverCasillas;
				    				if(((x1-moverCasillas)>=0 && (x1-moverCasillas)<8) && ((y1+moverCasillas)>=0 && (y1+moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1-moverCasillas;
									    		y2=y1+moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1-i][y1+i]=="| N |") || (matriz_Tablero[x1-i][y1+i]=="|CN |") || (matriz_Tablero[x1-i][y1+i]=="|B |") || (matriz_Tablero[x1-i][y1+i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1-(moverCasillas-1)][y1+(moverCasillas-1)]=="| B |") || (matriz_Tablero[x1-(moverCasillas-1)][y1+(moverCasillas-1)]=="|CB |")){
					    								x2=x1-moverCasillas;
							    						y2=y1+moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1-(moverCasillas-1)][y1+(moverCasillas-1)]="|   |";
							    							conteoBlancas-=1;
														}
							    						cout << "\nFicha [" << x1-(moverCasillas-1) << "][" << y1+(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								case 2: //Derecha abajo
									std::cout << "N0. casillas a desplazarse ";
				    				std::cin >> moverCasillas;
				    				if(((x1+moverCasillas)>=0 && (x1+moverCasillas)<8) && ((y1+moverCasillas)>=0 && (y1+moverCasillas)<8)){
				    					if (moverCasillas>0){
							    			if (moverCasillas==1){
							    				x2=x1+moverCasillas;
									    		y2=y1+moverCasillas;
					    						puedeMover=movimiento(x1,y1,x2,y2);
											}else{
												for	(int i= i; i<moverCasillas; i++){
													if ((matriz_Tablero[x1+i][y1+i]=="| N |") || (matriz_Tablero[x1+i][y1+i]=="|CN |") || (matriz_Tablero[x1+i][y1+i]=="|B |") || (matriz_Tablero[x1+i][y1+i]=="|CB |")){
														piezas+=1;
													}
												}
												if (piezas==1){
													if ((matriz_Tablero[x1+(moverCasillas-1)][y1+(moverCasillas-1)]=="| B |") || (matriz_Tablero[x1+(moverCasillas-1)][y1+(moverCasillas-1)]=="|CB |")){
					    								x2=x1+moverCasillas;
							    						y2=y1+moverCasillas;
							    						puedeMover=movimiento(x1,y1,x2,y2);
							    						if(!puedeMover){
							    							matriz_Tablero[x1+(moverCasillas-1)][y1+(moverCasillas-1)]="|   |";
							    							conteoBlancas-=1;
														}
							    						cout << "\nFicha [" << x1+(moverCasillas-1) << "][" << y1+(moverCasillas-1) << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
						    							cin >> opcion;
				    									if (opcion!=1){
				    										puedeMover=true;
														}else{
															puedeMover=false;
														}
													}else{
														cout << "\nNo hay ficha para comer" << endl;
														system("pause");
														puedeMover=true;
													}
												}
												if(piezas==0){
													x2=x1-moverCasillas;
									    			y2=y1-moverCasillas;
					    							puedeMover=movimiento(x1,y1,x2,y2);
												}
											}
										}else{
											cout << "\nElija un valor mayor a 0" << endl;
											system("pause");
											puedeMover=true;
										}
									}else{
										cout << "\nNumero fuera de rango" << endl;
										system("pause");
										puedeMover=true;
									}
									break;
								default:
									break;
							}
							break;
				    	default:
		    				cout << "Opcion no valida";
		    				break;
					}
				}
	    	}else{
		        cargaPrevia();
    			if(blancas){
		    		switch(izquierda_derecha){
			    		case 1:
				    		moverCasillas= validacionEntrada("N0. casillas a desplazarse ", moverCasillas);
				    		if (izquierda_derecha)
				    		if(((x1-moverCasillas)>=0 && (x1-moverCasillas)<8) && ((y1-moverCasillas)>=0 && (y1-moverCasillas)<8)){
				    			if (moverCasillas<=2 && moverCasillas>0){
					    			if (moverCasillas==1){
					    				x2=x1-moverCasillas;
							    		y2=y1-moverCasillas;
					    				puedeMover=movimiento(x1,y1,x2,y2);
									}
									if (moverCasillas==2){
										if ((matriz_Tablero[x1-1][y1-1]=="| N |") || (matriz_Tablero[x1-1][y1-1]=="|CN |")){
				    						x2=x1-moverCasillas;
						    				y2=y1-moverCasillas;
				    						puedeMover=movimiento(x1,y1,x2,y2);
				    						if(!puedeMover){
							    				matriz_Tablero[x1-1][y1-1]="|   |";
							    				conteoNegras-=1;
											}
				    						cout << "\nFicha [" << x1-1 << "][" << y1-1 << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
				    						cin >> opcion;
				    						if (opcion!=1){
				    							puedeMover=true;
											}else{
												puedeMover=false;
											}
										}else{
											cout << "\nNo hay ficha para comer" << endl;
											system("pause");
											puedeMover=true;
										}
									}
								}else{
									cout << "\nElija un valor entre 1y2" << endl;
									system("pause");
									puedeMover=true;
								}
							}else{
								cout << "\nPosicion de destino no existe" << endl;
								system("pause");
								puedeMover=true;
							}
							break;
		    			case 2:
		    				std::cout << "N0. casillas a desplazarse ";
			    			std::cin >> moverCasillas;
			    			if(((x1-moverCasillas)>=0 && (x1-moverCasillas)<8) && ((y1+moverCasillas)>=0 && (y1+moverCasillas)<8)){
				    			if (moverCasillas<=2 && moverCasillas>0){
					    			if (moverCasillas==1){
					    				x2=x1-moverCasillas;
							    		y2=y1+moverCasillas;
					    				puedeMover=movimiento(x1,y1,x2,y2);
									}
									if (moverCasillas==2){
										if ((matriz_Tablero[x1-1][y1+1]=="| N |") || (matriz_Tablero[x1-1][y1+1]=="|CN |")){
											conteoNegras-=1;
				    						x2=x1-moverCasillas;
						    				y2=y1+moverCasillas;
				    						puedeMover=movimiento(x1,y1,x2,y2);
				    						if(!puedeMover){
							    				matriz_Tablero[x1-1][y1+1]="|   |";
											}
				    						cout << "\nFicha [" << x1-1 << "][" << y1+1 << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
				    						cin >> opcion;
				    						if (opcion!=1){
				    							puedeMover=true;
											}else{
												puedeMover=false;
											}
										}else{
											cout << "\nNo hay ficha para comer" << endl;
											system("pause");
											puedeMover=true;
										}
									}
								}else{
									cout << "\nElija un valor entre 1y2" << endl;
									system("pause");
									puedeMover=true;
								}
							}else{
								cout << "\nPosicion de destino no existe" << endl;
								system("pause");
								puedeMover=true;
							}
							break;
				    	default:
		    				cout << "Opcion no valida";
		    				break;
					}
				}
				if(negras){
		    		switch(izquierda_derecha){
			    		case 1:
			    			moverCasillas= validacionEntrada("N0. casillas a desplazarse ", moverCasillas);
				    		if(((x1+moverCasillas)>=0 && (x1+moverCasillas)<8) && ((y1-moverCasillas)>=0 && (y1-moverCasillas)<8)){
				    			if (moverCasillas<=2 && moverCasillas>0){
					    			if (moverCasillas==1){
					    				x2=x1+moverCasillas;
							    		y2=y1-moverCasillas;
					    				puedeMover=movimiento(x1,y1,x2,y2);
									}
									if (moverCasillas==2){
										if ((matriz_Tablero[x1+1][y1-1]=="| B |") || (matriz_Tablero[x1+1][y1-1]=="|CB |")){
											x2=x1+moverCasillas;
						    				y2=y1-moverCasillas;
				    						puedeMover=movimiento(x1,y1,x2,y2);
				    						if(!puedeMover){
							    				matriz_Tablero[x1+1][y1-1]="|   |";
							    				conteoBlancas-=1;
											}
				    						cout << "\nFicha [" << x1+1 << "][" << y1-1 << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
				    						cin >> opcion;
				    						if (opcion!=1){
				    							puedeMover=true;
											}else{
												puedeMover=false;
											}
										}else{
											cout << "\nNo hay ficha para comer" << endl;
											system("pause");
											puedeMover=true;
										}
									}
								}else{
									cout << "\nElija un valor entre 1y2" << endl;
									system("pause");
									puedeMover=true;
								}
							}else{
								cout << "\nPosicion de destino no existe" << endl;
								system("pause");
								puedeMover=true;
							}
							break;
		    			case 2:
		    				std::cout << "N0. casillas a desplazarse ";
			    			std::cin >> moverCasillas;
			    			if(((x1+moverCasillas)>=0 && (x1+moverCasillas)<8) && ((y1+moverCasillas)>=0 && (y1+moverCasillas)<8)){
				    			if (moverCasillas<=2 && moverCasillas>0){
					    			if (moverCasillas==1){
					    				x2=x1+moverCasillas;
							    		y2=y1+moverCasillas;
					    				puedeMover=movimiento(x1,y1,x2,y2);
									}
									if (moverCasillas==2){
										if ((matriz_Tablero[x1+1][y1+1]=="| N |") || (matriz_Tablero[x1+1][y1+1]=="|CN |")){
											conteoBlancas-=1;
				    						x2=x1+moverCasillas;
						    				y2=y1+moverCasillas;
				    						puedeMover=movimiento(x1,y1,x2,y2);
				    						if(!puedeMover){
							    				matriz_Tablero[x1+1][y1+1]="|   |";
											}
				    						cout << "\nFicha [" << x1+1 << "][" << y1+1 << "] ha sido capturada...Volver a mover? 1.Si/2.No: ";
				    						cin >> opcion;
				    						if (opcion!=1){
				    							puedeMover=true;
											}else{
												puedeMover=false;
											}
										}else{
											cout << "\nNo hay ficha para comer" << endl;
											system("pause");
											puedeMover=true;
										}
									}
								}else{
									cout << "\nElija un valor entre 1y2" << endl;
									system("pause");
									puedeMover=true;
								}
							}else{
								cout << "\nPosicion de destino no existe" << endl;
								system("pause");
								puedeMover=true;
							}
							break;
				    	default:
		    				cout << "Opcion no valida";
		    				break;
					}
				}
	    	}
		}while(puedeMover);
		
		//control del turno
		if(blancas){
			blancas=false;
			negras=true;
		}else{
			blancas=true;
			negras=false;
		}
	}while((conteoBlancas>0) || (conteoNegras>0));
	system("cls");
	encabezado(jugador1,jugador2);
	cargaTablero(matriz_Tablero);
	if (conteoBlancas==0){
		std::cout << "!!!!!!!Victoria de las negras(" << jugador2 << ")!!!!!!!" << std::endl;
	}else{
		std::cout << "!!!!!!!Victoria de las blancas(" << jugador1 << ")!!!!!!!" << std::endl;
	}
	system("pause");
	system("exit");
}
