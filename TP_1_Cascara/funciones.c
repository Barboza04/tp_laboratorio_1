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
/** \brief recibe un número y calcula su factorial usando recursividad
 *
 * \return la 1er sentencia inicia la recursividad multiplicando x por la propia funcion de x-1 hasta que x valga 1
 * \return la 2da sentencia al devolver 1 a la funcion, inicia el camino inverso de la anterior, devolviendo asi los valores para resolver todos los calculos de x * factorial(x-1)
 */
int factorial(int x)
{
    if(x>1)
    {
        return x * factorial(x-1);
    }
    return 1;
}
