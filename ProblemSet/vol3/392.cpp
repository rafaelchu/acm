// 392 - Polynomial Showdown

#include <stdio.h>

int main()
{
		  int Coef;
		  int Exp;
		  short int Found;


		  //read input
		  while (scanf("%d", &Coef) != EOF) {
					Found = 0;
					if (Coef != 0) {
							  if (Coef == 1)
									printf("x^8");
							  else if (Coef == -1)
									printf("-x^8");
							  else
									printf("%dx^8", Coef);

							  Found = 1;
							  Exp= 7;
					}
					else
					 for (Exp = 7; Exp > 0; Exp--) {
								scanf("%d", &Coef);
								if (Coef != 0) {
										  if (Coef == 1 || Coef == -1) {
													 if (Coef != 1)
														printf("-");

													 if (Exp != 1)
																printf("x^%d", Exp);
													 else
																printf("x");
										  }
										  else {
													 if (Exp != 1)
																printf("%dx^%d", Coef, Exp);
													 else
																printf("%dx", Coef);

										  }

										  Found = 1;
										  Exp--;
										  break;
								}
					 }

					 //read rest coef except exp = 0
					 for (; Exp > 0; Exp--) {
								scanf("%d", &Coef);
								if (Coef != 0) {
										  if (Coef == 1 || Coef == -1) {
											  if (Coef == 1)
													 printf(" + x");
											  else
													 printf(" - x");
										  }
										  else if (Coef > 0)
													 printf(" + %dx", Coef);
										  else
													 printf(" - %dx", Coef*-1);

										  if (Exp != 1)
													 printf("^%d", Exp);
								}
					 }

					 //read last coef
					 scanf("%d", &Coef);

					 if (Found) {
								if (Coef > 0)
										  printf(" + %d\n", Coef);
								else if (Coef < 0)
										  printf(" - %d\n", Coef*-1);
								else
										  printf("\n");
					 }
					 else
								printf("%d\n", Coef);

		  }

		  return 0;		
}