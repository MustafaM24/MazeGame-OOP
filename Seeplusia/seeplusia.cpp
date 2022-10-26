#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 20, nCrystalsFound = 0, crystalSoD = 1, crystalMoU = 1, crystalWH = 1, crystalET = 1;
string gameState  = "Running";
string location="Enchanted Forest";

void eastMove(){ // Funtion for every time right arrow is pressed.
    	if (location=="Enchanted Forest" && applesLeft >= 1){
			location="Swamps of Despair";
            moveEast(); 
			applesLeft-=1; 
			if (crystalSoD>0){
			nCrystalsFound = nCrystalsFound + crystalSoD; //crystal added at Swamps
			crystalSoD = 0; 
			}
			if (applesLeft <= 0){ // If apples finished we will loose
				gameState = "Lost";
			}			
		}
		else if (location=="Bridge of Death" && applesLeft >= 2){
			location="Enchanted Forest";
            moveEast(); 
			applesLeft-=2; 
			if (applesLeft <= 0){
				gameState = "Lost";
		}
		}
		else if (location=="Apple Orchard" && applesLeft >= 1){
			location="Wampire Cove";
            moveEast(); 
			applesLeft-=1; 
			if (applesLeft <= 0){
				gameState = "Lost";
		}
		}
		else if (location=="Wampire Cove" && applesLeft >= 1){
			location="Marsh of Undead";
            moveEast(); 
			applesLeft-=1; 
			if (crystalMoU>0){
			nCrystalsFound = nCrystalsFound + crystalMoU; //crystal added at MOU
			crystalMoU = 0; // crystal made zero after being used up
			}
			if (applesLeft <= 0){
				gameState = "Lost";
		}
		}
		else if (location=="Eisten Tunnel" && applesLeft >=2){
			location="Elvin Waterfall";
            moveEast(); 
			applesLeft-=2; 
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Elvin Waterfall" && applesLeft >=2){
			location="Werewolf Hill";
            moveEast(); 
			applesLeft-=2; 
			if (crystalWH>0){
			nCrystalsFound = nCrystalsFound + crystalWH; //crystal added at werewolf
			crystalWH = 0; // crystal made zero after being used up
			}
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Werewolf Hill" && applesLeft >=1){
			location="Sounds of Quick";
            moveEast(); 
			applesLeft-=1; 
			gameState = "Lost";
		}
		else if (gameState == "Running"){ // for evry void move one apple reduced.
			applesLeft--; 
			if (applesLeft <= 0){
				gameState = "Lost";
			}
		}
}
void westMove(){ // Funtion for every time left arrow is pressed.	
		if (location=="Swamps of Despair" && applesLeft >= 1){
			location ="Enchanted Forest";
            moveWest(); 
			applesLeft-=1; 
			if (applesLeft <= 0){
				gameState = "Lost";
			}
		}
		else if (location=="Enchanted Forest" && applesLeft >= 2){
			location="Bridge of Death";
            moveWest(); 
			applesLeft-=2; 
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Bridge of Death" && applesLeft >=5 && nCrystalsFound >= 4){// 3 crystals to go to wizard's castle
			location="Wizard's Castle";
			moveWest(); 
			applesLeft-=5; 
			gameState = "Won"; // game won
		}
		else if (location=="Marsh of Undead" && applesLeft >= 1){
			location="Wampire Cove";
            moveWest(); 
			applesLeft-=1; 
			// applesLeft+=6; // apples added
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Wampire Cove" && applesLeft >= 1){
			location="Apple Orchard";
            moveWest(); 
			applesLeft-=1; 
			applesLeft+=6;
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Werewolf Hill" && applesLeft >= 2){
			location="Elvin Waterfall";
            moveWest(); 
			applesLeft-=2; 
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Elvin Waterfall" && applesLeft >= 2){
			location="Eisten Tunnel";
            moveWest(); 
			applesLeft-=2; 
			if (crystalET>0){
			nCrystalsFound = nCrystalsFound + crystalET; //crystal added at werewolf
			crystalET = 0; // crystal made zero after being used up
			}
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (gameState == "Running"){ // for evry void move one apple reduced.
			applesLeft--; 
			if (applesLeft <= 0){
				gameState = "Lost";
			}
		}

}
void northMove(){ // Funtion for every time up arrow is pressed.
		if (location=="Wampire Cove" && applesLeft >= 3){
			location="Enchanted Forest";
			moveNorth();
			applesLeft-=3; 
			// applesLeft+=6; // apples added
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Werewolf Hill" && applesLeft >= 3){
			location="Wampire Cove";
			moveNorth();
			applesLeft-=3; 
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Eisten Tunnel" && applesLeft >= 10){
			location="Wizards Castle";
			moveNorth();
			moveNorth();
			applesLeft-=10; 
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (gameState == "Running") { // for evry void move one apple reduced.
			applesLeft--; 
			if (applesLeft <= 0){
				gameState = "Lost";
			}
		}
}
void southMove(){ // Funtion for every time down arrow is pressed.
		if (location=="Enchanted Forest" && applesLeft >= 3){
			location="Wampire Cove";
			moveSouth();
			applesLeft-=3;	
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Wampire Cove" && applesLeft >= 3){
			location="Werewolf Hill";
			moveSouth();
			applesLeft-=3; 
			if (crystalWH>0){
			nCrystalsFound = nCrystalsFound + crystalWH; //crystal added at werewolf
			crystalWH = 0; // crystal made zero after being used up
			}
			if (applesLeft <= 0){
			gameState = "Lost";
		}
		}
		else if (location=="Marsh of Undead" && applesLeft >= 1){
			location="Sounds of Quick";
			moveSouth();
			applesLeft-=1; 
			gameState = "Lost";
		}
		else if (gameState == "Running"){ // for evry void move one apple reduced.
			applesLeft--; 
			if (applesLeft <= 0){
				gameState = "Lost";
			}
		}
}
void makeMove(string direction){
	if (direction == "East"){ 
	eastMove(); // Function called to move in East direction.
	}
	else if (direction == "West"){ 	
		westMove(); // Function called to move in West direction.
	}
	else if (direction == "North"){
		northMove(); // Function called to move in North direction.
	}
	else if (direction == "South"){
		southMove(); // Function called to move in South direction.
	}
}
