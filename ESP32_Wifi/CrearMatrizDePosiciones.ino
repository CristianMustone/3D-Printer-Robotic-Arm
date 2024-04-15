// void MatrizDeMovimientos(char* gcode_string){
//   int comandoG = 0;
//   char* line;
//   line = strtok(gcode_string, ",");
//   while (line != NULL) {
//     if (line[0] == 'G') {
//       comandoG = 1;

//       char newX[20]="0";
//       char newY[20]="0";
//       char newZ[20]="0";
//       char* PosX = 0;
//       char* PosY = 0;
//       char* PosZ = 0;
//       char* PosE = 0;
//       bool Fx, Fy, Fz, Fe = true;
//       size_t Px,Py,Pe,Pz=0;

//       switch (line[1]){
//         case '0':
//           /*X e Y Siempre
//           E nunca
//           Z quizas*/
//           //------------------------------------- Extrayendo Z si la hay      ----------------------------
//           if (TryCatch('Z',line)){
//             PosZ=strchr(line,'Z');
//             Pz = PosZ - line;
//             size_t lengthZ = strlen(line) - Pz;
//             extractSubstring(line, newZ, Pz + 1, lengthZ);
//             Fz = true;
//           } else {
//             Fz = false;
//           }
//           //------------------------------------- Extrayendo X e Y  ----------------------------
//           //obtengo la posicion de X e Y

//           PosX=strchr(line,'X');
//           Px= PosX - line;
//           Fx = true;

//           PosY=strchr(line,'Y');
//           Py = PosY - line;
//           Fy = true;

//           if (Fx && Fy){
//             size_t lengthX = Py - Px - 1;
//             extractSubstring(line, newX, Px + 1, lengthX);
//           }
//           if (Fy && Fz){
//             size_t lengthY = Pz - Py - 1;
//             extractSubstring(line, newY, Py + 1, lengthY);
//           } else {
//             size_t lengthY = strlen(line) - Py + 1;
//             extractSubstring(line, newY, Py + 1, lengthY);
//           }
          

//           Movimientos[Filas][0] = atof(newX);
//           Movimientos[Filas][1] = atof(newY);
//           Movimientos[Filas][2] = atof(newZ);

//           break;

//         case '1':
//           /*X e Y quizas
//           E siempre
//           Z nunca*/
//           //------------------- Revisando si hay X e Y ---------------------------------
//           if (TryCatch('X',line)){
//             PosX=strchr(line,'X');
//             Px= PosX - line;
//             Fx=true;
//           } else {
//             Fx = false;
//           }
//           if (TryCatch('Y',line)){
//             PosY=strchr(line,'Y');
//             Py = PosY - line;
//             Fy=true;
//           } else {
//             Fy = false;
//           }
//           if (TryCatch('E',line)){
//             PosE=strchr(line,'E');
//             Pe = PosE - line;
//             Fe=true;
//           } else {
//             Fe = false;
//           }
//           if (Fx && Fy){
//             size_t lengthX = Py - Px - 1;
//             extractSubstring(line, newX, Px + 1, lengthX);
//           }
//           if (Fy && Fe){
//             size_t lengthY = Pe - Py - 1;
//             extractSubstring(line, newY, Py + 1, lengthY);
//           }

//           Movimientos[Filas][0] = atof(newX);
//           Movimientos[Filas][1] = atof(newY);
//           Movimientos[Filas][2] = 0;

//           break;
//         default:
//           break;
//       }
//       Filas++;
//     }
//     line = strtok(NULL, ",");
//   }
// }