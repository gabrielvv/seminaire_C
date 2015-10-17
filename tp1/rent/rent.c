#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

  if (argc != 3 && 1) {
    printf("Nombre de parametres insuffisant\n");
    return 1;
  }

  int i, distance = atoi(argv[1]), days = atoi(argv[2]), kmPerDay[days];
  float totalDiesel, totalEssence, temp, dieselPricePerDay[days], bestPrice;
  char bestCarburant;

  totalDiesel = totalEssence = 0;

  for(i = 0; i < days; i++)
    kmPerDay[i] = distance/days;

  kmPerDay[days-1] += (distance % days);

  for(i = 0; i < days; i++){
    (temp = kmPerDay[i]*0.13) > 10 ? (totalEssence += temp) : (totalEssence += 10);
    (temp = kmPerDay[i]*0.11) > 8 ? (totalDiesel += temp) : (totalDiesel += 8);
    totalEssence += 30;
    totalDiesel += 33.4;
  }

  (totalEssence < totalDiesel) ? (bestCarburant = 'e') : (bestCarburant = 'd');
  (totalEssence < totalDiesel) ? (bestPrice = totalEssence) : (bestPrice = totalDiesel);

  printf("e %.2f d %.2f m %c %.2f", (totalEssence*1.196), (totalDiesel*1.196), bestCarburant, (bestPrice*1.196));

  return 0;
}
