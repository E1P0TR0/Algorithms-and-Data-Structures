/*  INFIX, PREFIX AND POSTFIX */

/**
* Son una combinación de symbolos que puede ser numeros,
variables, operaciones, símbolos de agrupación.
*! la combinación infix a pesar de ser legible para el humano
*! no es eficiente para la lectura de una máquima
**en cambio posfix y prefix no necesitan conceptos de precedencia
**y asociatividad y pos eso será ma eficiente analizar estas expresiones


*@param OPERANDO - //* numeros, variables, etc
*@param OPERADOR   //* +, - , * , /
*/

//? Infix -> <operand> <operator> <operand>
//! Posfix -> <operand> <operand> <operator>
//* Prefix -> <operator> <operand> <operand>


/**
 *TODO : ORDEN DE OPERACIONES 
 **parentesis {}[]()
 **exponentes (r->l) a^b, 2^4
 **Múltiplicación y división (l->r) a * b / c
 **Suma y resta (l->r) a + b - c
 *! (Asociatividad)
*/
