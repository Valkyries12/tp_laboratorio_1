/*
 * utn.h
 *
 *  Created on: 14 abr 2022
 *      Author: Nicol�s Caruso
 */

#ifndef UTN_H_
#define UTN_H_


/// @brief Solicita un n�mero al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor m�nimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita un n�mero flotante al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor m�nimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos);

/// @brief Solicita una letra al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pCaracterIngresado Puntero al resultado alli se dejara el caracter ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor m�nimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getCaracter(char * pCaracterIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos);


/// @brief  Solicita un texto al usuario, lo valida, verifica y devuelve el resultado
///
/// @param stringAIngresar -> puntero al resultado, alli se dejara la frase ingresada por el usuario
/// @param mensaje -> Es el mensaje a ser mostrado
/// @param mensajeError -> Es el mensaje a ser mostrado en caso de error
/// @param maximoReintentos -> Cantidad de reintentos en caso de error
/// @param lenMinima -> longitud minima requerida de caracteres
/// @param lenMaxima -> longitud maxima requerida de caracteres
/// @return En caso de exito (0), en caso de error (-1)
int utn_getString(char * stringAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int lenMinima, int lenMaxima);



/// @brief  Solicita un texto al usuario, lo valida, verifica y devuelve el resultado
///
/// @param stringAIngresar -> puntero al resultado, alli se dejara la frase ingresada por el usuario
/// @param mensaje -> Es el mensaje a ser mostrado
/// @param mensajeError -> Es el mensaje a ser mostrado en caso de error
/// @param maximoReintentos -> Cantidad de reintentos en caso de error
/// @param lenMinima -> longitud minima requerida de caracteres
/// @param lenMaxima -> longitud maxima requerida de caracteres
/// @return En caso de exito (0), en caso de error (-1)
int utn_getStringConNumero(char * stringAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int lenMinima, int lenMaxima);


/// @brief verifica si la cadena tiene caracteres especiales
///
/// @param arr -> cadena a verificar
/// @return en caso de encontrar caracteres especiales (TRUE), sino (FALSE)
int utn_tieneCaracteresEspeciales(char arr[]);


///// @brief  convierte un numero flotante en string
/////
///// @param numero -> numero flotante a convertir
///// @param arr -> puntero a guardar el string
///// @return En caso de exito (0), en caso de error (-1)
//int utn_ftoa(float numero, char* arr);



/// @brief Solicita al usuario un telefono (formato string), lo valida, verifica y devuelve resultado
///
/// @param telefonoAIngresar -> puntero al resultado, alli se dejar� el telefono ingresado por el usuario
/// @param mensaje -> es el mensaje a ser mostrado
/// @param mensajeError -> es el mensaje a ser mostrado en caso de error
/// @param maximoReintentos -> cantidad de reintentos en caso de error
/// @param len -> longitud maxima del telefono
/// @return -> En caso de exito (0), en caso de error (-1)
int utn_getTelefono(char * telefonoAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int len);



/// @brief Solicita al usuario un numero de documento, lo valida, verifica y devuelve un resultado
///
/// @param numeroDocumento -> puntero al resultado, alli se dejara el el documento ingresado por el usuario
/// @param mensaje -> es el mensaje en el ingreso de datos
/// @param mensajeError -> es el mensaje en caso de error
/// @param maximoReintentos -> cantidad de reintenttos en caso de error
/// @param len -> longitud maxima del documento
/// @return -> En caso de exito (0), en caso de error (-1)
int utn_getDocumento(int * numeroDocumento, char * mensaje, char * mensajeError, int maximoReintentos);



int utn_getMail(char * mailAIngresar, char * mensaje, char * mensajeError, int maximoReintentos);


/// @brief Solicita usuario y contrase�a,lo valida, verifica y devuelve un resultado
///
/// @param pIsLogged Puntero al resultado alli se dejar� TRUE o FALSE si fue logeado o no
/// @param intentosMaximos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_loguear(int * pIsLogged, int intentosMaximos);



/// @brief Hace un n% descuento , lo verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace el descuento
/// @param descuento -> porcentaje a descontar sobre el monto
/// @param pValorFinal -> Puntero al resultado, alli se dejar� el monto final con el descuento correspondiente
/// @return En caso de exito (0), en caso de error (-1)
int utn_hacerDescuento(float monto, int descuento, float * pValorFinal);



/// @brief Agrega un n% de interes, lo verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace el descuento
/// @param interes -> porcentaje a agregar sobre el monto
/// @param pValorFinal -> Puntero al resultado, alli se dejar� el monto final con el descuento correspondiente
/// @return En caso de exito (0), en caso de error (-1)
int utn_sumarInteres(float monto, int interes, float * pValorFinal);


/// @brief calcula el costo del pasaje en Bitcoin o precio unitario del km, verifica , valida y devuelve un resultado
///
/// @param cantidad -> cantidad  sobre el que se hace el calculo
/// @param precio -> precio  actual
/// @param pValorFinal -> putenro al resultado, alli se dejara la conversion final de divisas
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularPrecio(float cantidad, float precio, float * pValorFinal);


/// @brief resta dos numeros flotantes, valida y verifica. Devuelve el resultado
///
/// @param num1 -> operando a restar
/// @param num2 -> operando a restar
/// @param pResultado -> puntero al resultado, alli se pondra el resultado
/// @return devuelve (0) en caso de exito y (-1) en caso de error
int utn_restarNumeroFlotante(float num1, float num2, float * pResultado);


///// @brief calcula el precio unitario del km, verifica y valida, devuelve un resultado
/////
///// @param kilometro -> kilometros ingresados
///// @param precio -> precio total del vuelo
///// @param pValorFinal -> puntero al resultado, alli se dejara el precio unitario
//int utn_calcularPrecioPorKilometro(int kilometro, float precio, float * pValorFinal);



/// @brief Verifica si la respuesta es exitosa o no y en base a ello imprime un mensaje
///
/// @param hayError -> respuesta para verificacion (0) es exito y (-1) error
/// @param mensaje -> Es el mensaje a ser mostrado en caso de exito
/// @param mensajeError -> Es el mensaje a ser mostrado en caso de error
/// @return no retorna nada
void utn_imprimirMensajes(int hayError, char * mensaje, char * mensajeError);


/// @brief Cuenta la cantidad de enteros positivos
///
/// @param arr[] -> array de enteros previamente creado
/// @param cantidadPositivos -> puntero a mostrar el resultado de la cantidad de positivos
/// @param longitudArray -> longitud del array para iterar
/// @return En caso de exito (0), en caso de error (-1)
int utn_contarPositivos(int arr[], int * cantidadPositivos, int longitudArray);


/// @brief Cuenta la cantidad de enteros negativos
///
/// @param arr[] -> array de enteros previamente creado
/// @param cantidadNegativos -> puntero a mostrar el resultado de la cantidad de negativos
/// @param longitudArray -> longitud del array para iterar
/// @return En caso de exito (0), en caso de error (-1)
int utn_contarNegativos(int arr[], int * cantidadNegativos, int longitudArray);


/// @brief Inicializa todos los valores del array en cada indice
///
/// @param arr -> array a ser inicializado
/// @param len -> longitud del array
/// @param valorInicial -> valor inicial por cada indice
/// @return En caso de exito (0), en caso de error (-1)
int utn_inicializarArrayDeEnteros(int arr[], int len, int valorInicial);


/// @brief Inicializa todos los valores del array en cada indice
///
/// @param arr -> array a ser inicializado
/// @param len -> longitud del array
/// @param valorInicial -> valor inicial por cada indice
/// @return En caso de exito (0), en caso de error (-1)
int utn_inicializarArrayDeFloats(float arr[], int len, float valorInicial);



/// @brief Suma los numeros pares del array
///
/// @param arr -> Array que contiene numeros enteros
/// @param len -> longitud del array
/// @param resultadoSuma -> puntero donde ira alojada la suma de los pares
/// @return En caso de exito (0), en caso de error (-1)
int utn_sumarEnterosParesDelArray(int arr[], int len, int * resultadoSuma);


/// @brief Calcular el numero impar mayor
///
/// @param arr -> Array que contiene numero enteros
/// @param len-> longitud del array
/// @param mayorImpar punteto donde ira alojado el mayor impar
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularEnteroMayorImpar(int arr[], int len, int * mayorImpar);


/// @brief Imprime todos los valores del array
///
/// @param arr -> Array que contiene numeros enteros
/// @param len -> Longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirEnterosArray(int arr[], int len);



/// @brief Imprime los valores pares del array
///
/// @param arr -> array que contiene numeros enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirEnterosParesArray(int arr[], int len);


/// @brief Imprime los valores de las posiciones impares del array
///
/// @param arr -> Array que contiene numeros enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirEnterosDePosicionesImparesArray(int arr[],int len);


/// @brief Carga valores enteros en indices aleatorios
///
/// @param arr -> Array inicializado que contendr� numeros enteros
/// @param len -> Longitud del array
/// @param valor -> Valor entero a cargar
/// @param indice -> indice indicado para cargar el dato
/// @return En caso de exito (0), en caso de error (-1)
int utn_cargarEnteroEnIndiceAleatorio(int arr[], int len, int valor, int indice);


/// @brief Carga valores enteros en indices aleatorios
///
/// @param arr -> Array inicializado que contendr� numeros enteros
/// @param len -> Longitud del array
/// @param valor -> Valor entero a cargar
/// @param indice -> indice indicado para cargar el dato
/// @return En caso de exito (0), en caso de error (-1)
int utn_cargarFlotanteEnIndiceAleatorio(float arr[], int len, float valor , int indice);



/// @brief  Calcula el menor de los numeros enteros dependiendo si se dessea que sea negativo, positivo o ambos
///
/// @param arr -> array de numeros enteros
/// @param len -> longitud del array
/// @param pMenor -> puntero donde se almacenara el resultado
/// @param tipo -> (+) calcula el menor positivo, (-) calcula el menor negativo negativo, (=) calcula el menor de ambos tipos
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularMenorEntero(int arr[], int len, int * pMenor, char tipo);


/// @brief  Calcula el mayor de los numeros enteros dependiendo si se dessea que sea negativo, positivo o ambos
///
/// @param arr -> array de numeros enteros
/// @param len -> longitud del array
/// @param pMayor -> puntero donde se almacenara el resultado
/// @param tipo -> (+) calcula el mayor positivo, (-) calcula el mayor negativo negativo, (=) calcula el mayor de ambos tipos
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularMayorEntero(int arr[], int len, int * pMayor, char tipo);


/// @brief ordena de menor a mayor los enteros
///
/// @param arr -> array de enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_ordenarArrayMenorAMayor(int arr[], int len);


/// @brief ordena de menor a mayor los enteros
///
/// @param arr -> array de enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_ordenarArrayMayorAMenor(int arr[], int len);


/// @brief imprime la string dada (array de chars)
///
/// @param arr -> array de chars
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirString(char arr[]);


/// @brief devuelve TRUE (1) o FALSE(0) dependiendo si solo tiene letras
///
/// @param arr -> array de chars
/// @return En caso de tener solo letras TRUE (1), en caso de tener otro tipo de dato FALSE (0)
int utn_tieneSoloLetras(char arr[]);



/// @brief devuelve TRUE (1) o FALSE(0) dependiendo si solo tiene letras y numeros
///
/// @param arr -> array de chars
/// @return En caso de tener solo letras y numeros TRUE (1), en caso de tener otro tipo de dato FALSE (0)
int utn_tieneLetrasYNumeros(char arr[]);


/// @brief devuelve TRUE (1) o FALSE(0) dependiendo si solo tiene n�meros
///
/// @param arr -> array de chars
/// @return En caso de tener solo n�meros TRUE (1), en caso de tener otro tipo de dato FALSE (0)
int utn_esNumerico(char arr[]);



/// @brief Convierte la palabra a mayus
///
/// @param string -> palabra a convertir
/// return En caso de exito (0), en caso de error (-1)
int utn_convertirAMayuscula(char * string);



/// @brief Redimensiona un array de int
///
/// @param arr -> puntero de puntero de array de enteros
/// @param len -> puntero de la longitud del array a redimensionar
/// @param nuevaLen -> nueva longitud
/// @return En caso de error (-1), en caso de existo (0)
int utn_resizeIntArray(int** arr, int* len, int nuevaLen);



/// @brief Redimensiona un array de char
///
/// @param arr -> puntero de puntero de array de char
/// @param len -> puntero de la longitud del array a redimensionar
/// @param nuevaLen -> nueva longitud
/// @return En caso de error (-1), en caso de existo (0)
int utn_resizeCharArray(char** arr, int* len, int nuevaLen);



/// @brief Redimensiona un array de float
///
/// @param arr -> puntero de puntero de array de float
/// @param len -> puntero de la longitud del array a redimensionar
/// @param nuevaLen -> nueva longitud
/// @return En caso de error (-1), en caso de existo (0)
int utn_resizeFloatArray(float** arr, int* len, int nuevaLen);


/// @brief Busar un numero dado y lo elimina redimensionando el arr
///
/// @param arr -> arr de enteros
/// @param len -> longitud del arr
/// @param numeroABorrar -> numero entero a borrar
/// @return En caso de exito (0), en caso de error (-1)
int utn_removeIntFromArr(int arr[], int len, int numeroABorrar);



/// @brief Crea un espacio en memoria para un entero o array de enteros y devuelve su direccion
///
/// @param size -> longitud del arr
/// @return puntero del arr
int* utn_newEntero(int size);


/// @brief imprime los valores del puntero de enteros reservado en heap
///
/// @param pEntero -> puntero de enteros
/// @param len -> longitud del puntero
void utn_imprimirpEntero(int* pEntero, int len);









#endif /* UTN_H_ */
