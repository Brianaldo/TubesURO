//TUBES PROGRAMMING
//ROBOT PEMBASMI KECOAK MUTAN
//Brianaldo P (16520010) & Suryanto (16520195

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int x;
    int y;
} vektor;

//Fungsi-fungsi yang digunakan
/* Fungsi Gerak Robot, digunakan untuk menggerakkan robot sesuai masukan user*/
point gerakRobot (point robotPosisi,int masukan) {
    if (masukan == 1) {
        robotPosisi.y += 1;
    } else if (masukan == 2) {
        robotPosisi.y -= 1;
    } else if (masukan == 3) {
        robotPosisi.x += 1;
    } else if (masukan == 4) {
        robotPosisi.x -= 1;
    }
   
    return robotPosisi;				//mengembalikan nilai posisi baru
}


/*fungsi untuk menghitung jarak (dalam vektor)*/
vektor jarak (point a, point b) {
    vektor jarak;
    jarak.x = b.x - a.x;
    jarak.y = b.y - a.y;
    return jarak;
}

/*fungsi untuk menyerah*/
int menyerah() {
    return 0;
}

/*fungsi untuk menghitung jarak robot dan kecoak*/
float jarakRobotKecoa (vektor robotJarak) {
    float skalar;
    skalar = sqrt(pow(robotJarak.x,2) + pow(robotJarak.y,2));
    return skalar;
}

/*fungsi tembakan robot*/
int tembakRobot (vektor robotJarak, int kecoaHealth) {
    if ((robotJarak.y == 0 && robotJarak.x <= 3)||(robotJarak.x == 0 && robotJarak.y <= 3)) {
        kecoaHealth -= 5;
        printf("Kecoak terkena 5 damage!\n");	//robot hanya dapat menembak lurus sejajar sumbu x atau sejajar sumbu y dengan range maksimal sebesar 3 satuan
    } else {
        printf("Tembakan meleset!\n");
    }
    return kecoaHealth;
}

/* fungsi visualisasi */
//fungsi ini digunakan untuk menampilkan peta dan tataletak dari robot dan kecoak
int visualisasi (point posisiRobot, point posisiKecoa) {
    int i, j;
    for (i = 20; i >= 0; --i) {
        for (j = 0; j <= 20; ++j) {
            if ((posisiRobot.y == i) && (posisiRobot.x == j)) {
                printf("R ");			//jika robot berada pada i=4 dan j=5, maka pada titik 4,5 akan ditampilkan huruf R. begitu juga dengan kecoak
            } else if ((posisiKecoa.y == i) && (posisiKecoa.x == j)) {
                printf("K ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*fungsi cek validitas dari input*/
bool inputInvalid(int x, point robotPosisi, point kecoakPosisi){
	//dicek agar robot tidak keluar dari arena
    if ((x == 2) && (robotPosisi.y == 0)) {
        return true;
    } else if ((x == 4) && (robotPosisi.x == 0)) {
        return true;
    } else if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6){
    	//dicek agar robot tidak menabrak kecoak
    	if ((x==1) &&((kecoakPosisi.x==robotPosisi.x)&&(kecoakPosisi.y==robotPosisi.y+1))){
    		return true;
		}
		else if (((x==2))&&((kecoakPosisi.x==robotPosisi.x)&&(kecoakPosisi.y==robotPosisi.y-1))){
			return true;
		}
		else if (((x==3)) &&	((kecoakPosisi.x==robotPosisi.x+1)&&(kecoakPosisi.y==robotPosisi.y))){
			return true;
		}
		else if (((x==4)) && 	((kecoakPosisi.x==robotPosisi.x-1)&&(kecoakPosisi.y==robotPosisi.y))){
			return true;
   		} else{
			return false;
		}
	} else {
        return true;
    }
}

/*fungsi spawn*/
point spawn (point robot,point kecoak){
//fungsi ini akan memunculkan kecoak secara acak
    srand(time(NULL));
    kecoak.x = rand() % 20;
    kecoak.y = rand() % 20;
 	
 	//jika kecoak muncul di posisi robot, maka akan diacak lagi sehingga didapat posisi yang berbeda dengan robot
    while ((kecoak.x == robot.x) && (kecoak.y = robot.y)){
        kecoak.x  = rand() % 20;
        kecoak.y = rand() % 20;
    }

    return (kecoak);
}

/*fungsi serangan kecoak*/
//kecoak dapat menyerang robot
int serang(int robotHealth){
    robotHealth -= 5;
    return robotHealth;
}
 
/*fungsi gerak kecoak*/
//kecoak akan mencari jarak terdekat untuk mendekati robot
point mendekat(point robot, point kecoak){
 if (abs(robot.x-kecoak.x) <= abs(robot.y-kecoak.y)) {
  if ((kecoak.y-robot.y)<0) {
   kecoak.y += 1;
   
   return (kecoak);}
  else { 
   kecoak.y -= 1;
   return (kecoak); 
   }
 }
 else {  // (abs(robot.x - kecoak.x) > fabs(robot.y-kecoak.y))
  if ((kecoak.x - robot.x) <0) {
   kecoak.x += 1;
   return (kecoak);}
  else {
   kecoak.x -= 1;
   return (kecoak); }
   }
  }

int main() {
    point posisiRobot, posisiKecoak;
    vektor robotJarak, kecoakJarak;
    int robotHealth,kecoakHealth,count,Distance,input;
    bool validasiInput;
    
    robotHealth = 100;
    kecoakHealth = 20;
    count = 0;
    posisiRobot.x = 0;
    posisiRobot.y = 0;
    posisiKecoak = spawn(posisiRobot,posisiKecoak);
   
    while (robotHealth > 0){		//program akan berjalan selama robot masih hidup
        printf("\n            VISUALISASI PETA\n\n");
        visualisasi (posisiRobot, posisiKecoak);				//memunculkan peta
        robotJarak = jarak(posisiRobot, posisiKecoak);

        printf("\n                INFORMASI\n");
        printf("\nDarah robot : %d",robotHealth);
        printf("\nDarah kecoak : %d",kecoakHealth);
        printf("\nVektor jarak robot dengan kecoak:");
        printf("\nSumbu-x : %d i",robotJarak.x);
        printf("\nSumbu-y : %d j",robotJarak.y);
        printf("\nSkalar : %f\n",jarakRobotKecoa(robotJarak));
        printf("\nKecoak terbunuh: %d",count);

        /* input */
        printf("\n             DAFTAR PERINTAH\n\n");
        printf("(1) ATAS\n");
        printf("(2) BAWAH\n");
        printf("(3) KANAN\n");
        printf("(4) KIRI\n");
        printf("(5) TEMBAK\n");
        printf("(6) MENYERAH\n");
        printf("\nMasukan Kode Perintah (1 - 6) : ");
        scanf("%d", &input);
        validasiInput = inputInvalid(input, posisiRobot,posisiKecoak);

        while (validasiInput) {		//jika input salah, maka user diminta input yang benar (dianggap dunianya freeze sambil menunggu input user)
            printf("Masukan Invalid!");
            printf("\nMasukan Kode Perintah (1 - 6) : ");
            scanf("%d", &input);
            validasiInput = inputInvalid(input, posisiRobot,posisiKecoak);
        }

        if (input == 6) {		//jika robot sudah menyerah
            robotHealth = menyerah();
        } else {
            if (input == 5) {
                kecoakHealth = tembakRobot(robotJarak ,kecoakHealth);
                printf("Darah kecoak tersisa %d\n", kecoakHealth);
            } else {
                posisiRobot = gerakRobot(posisiRobot, input);
                printf("Robot berpindah ke (%d,%d)!\n", posisiRobot.x, posisiRobot.y);
            }

            /* cek apakah kecoak masih hidup */
            if (kecoakHealth == 0) {
                posisiKecoak = spawn(posisiRobot,posisiKecoak);
                kecoakHealth = 20;
                count += 1;
            }
            
            /* giliran kecoak */
            kecoakJarak = jarak(posisiKecoak, posisiRobot);
            if (pow(kecoakJarak.x,2) + pow(kecoakJarak.y,2) <= 2) {
                robotHealth = serang(robotHealth);
            } else {
                posisiKecoak = mendekat(posisiRobot, posisiKecoak);
            }
        }
    }

    printf("\n                SELESAI\n");
    printf("\nKecoak yang terbunuh : %d\n\n", count);
    return 0;
}
