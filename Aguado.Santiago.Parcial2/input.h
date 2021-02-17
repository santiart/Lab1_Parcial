#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/** \brief
 *
 * \param mensaje[] char
 * \param input[] char
 * \return int
 *
 */
int getValidStringNumeros(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght);
/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[]);

/** \brief funcion que recibe un caracter validando que sea f o m y los pasa a mayuscula
 *
 * \param mensaje[] char Es el mensaje a ser mostrado
 * \param mensajeError[] char Mensaje de error
 * \param input char* puntero a un caracter
 * \return char devuelve el caracter f O m en mayuscula
 *
 */
char getSexChar(char mensaje[],char mensajeError[],char* input);

/** \brief Funcion que pasa una a cadena a miniscula y su primer elemento a mayuscula
 *
 * \param cadena[] char la cadena a ser convertida
 * \return void no retorna nada
 *
 */
void stringToUpper(char cadena[]);

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo n�meros, "@" y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene datos alfanumericos que no empiezen en numeros, espacios y un "@".
 *
 */
int esEmail(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[], int lowLimit,int highLimit);

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/** \brief Solicita un n�mero al usuario y lo valida

 * \param requestMessage[] char Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage[] char Es el mensaje a ser mostrado en caso de error
 * \param lowLimit int el menor numero posible de cargar
 * \param hiLimit int Limite superior a validar
 * \param input int* Se carga el numero ingresado
 * \return int Si obtuvo el numero [0] si no [-1]
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return  Si obtuvo la cadena [0] si no [-1]
 *
 */
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght);

/** \brief Solicita un numero flotante al usuario y lo valida
 *
 * \param requestMessage[] char Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage[] char Es el mensaje a ser mostrado en caso de error
 * \param lowLimit float  Limite inferior a validar
 * \param hiLimit float Limite superior a validar
 * \param input float* Se carga el numero ingresado
 * \return int  Si obtuvo el numero [0] si no [-1]

 *
 */
int getValidFloat(char requestMessage[],char errorMessage[], float lowLimit, float hiLimit,float* input);

/** \brief
 *
 * \param void
 * \return void
 *
 */
void menu(void);




#endif // INPUT_H_INCLUDED
