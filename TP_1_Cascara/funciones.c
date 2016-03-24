/** \brief recibe dos números y los suma
 *
 * \param x primero número ingresado
 * \param y segundo número ingresado
 * \param suma guarda el resultado de la operacion
 *
 */
void suma(int x, int y)
{
    int suma;
    suma=x+y;
    printf("La suma es: %d\n", suma);
}
/** \brief recibe dos números y los resta
 *
 * \param x primero número ingresado
 * \param y segundo número ingresado
 * \param resta guarda el resultado de la operacion
 *
 */
void resta(int x, int y)
{
    int resta;
    resta=x-y;
    printf("La resta es: %d\n", resta);
}
/** \brief recibe dos números y los divide
 *
 * \param x primero número ingresado
 * \param y segundo número ingresado
 * \param division guarda el resultado de la operacion
 *
 */
void division(int x, int y)
{
    float division;
    while(y==0)
    {
        printf("No puede dividir por 0\nReingrese el 2do operando ");
        scanf("%d", &y);
    }
    division=(float)x/y;
    printf("La division es: %.2f\n", division);
}
/** \brief recibe dos números y los multiplica
 *
 * \param x primero número ingresado
 * \param y segundo número ingresado
 * \param multiplicacion guarda el resultado de la operacion
 *
 */
void multiplicacion(int x, int y)
{
    int multiplicacion;
    multiplicacion=x*y;
    printf("La multiplicacion es: %d\n", multiplicacion);
}
/** \brief recibe un número y calcula su factorial
 *
 * \param x número sobre el que se quiere calcular el factorial
 * \param i variable de control
 * \param factorial guarda el resultado de la multiplicacion
 *
 */
void factorial(int x)
{
    int i=1;
    int factorial=1;
    for(i;i<=x;i++)
    {
        factorial=factorial*i;
    }
    printf("El factorial de %d es: %d\n",x,factorial);
}
