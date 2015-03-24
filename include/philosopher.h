/* 
* @Author: Erick Lucena Palmeira Silva
* @Date:   2015-03-21 15:46:01
* @Last Modified by:   Erick Lucena Palmeira Silva
* @Last Modified time: 2015-03-23 19:34:54
*/

#ifndef _ELUCENAP_PHILOSOPHER_H
#define _ELUCENAP_PHILOSOPHER_H

void setTable (int seats, int meals);
void* philosopher(void* id);
void think (int id);
void eat(int id);

#endif
