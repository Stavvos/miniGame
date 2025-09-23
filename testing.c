#include "stdio.h"
#include "types.h"

//used to print a meaningful player state rather than a number
const char* getPlayerMoveStateString(PlayerMoveState state){
  switch (state)
  {
    case MOVEFORWARD: return "MOVEFORWARD";
    case MOVEBACKWARD: return "MOVEBACKWARD";
    case MOVELEFT: return "MOVELEFT";
    case MOVERIGHT: return "MOVERIGHT";
    case NOMOVE: return "NOMOVE";
    case MOVEUPRIGHT: return "MOVEUPRIGHT";
    case MOVEUPLEFT: return "MOVEUPLEFT";
    case MOVEDOWNRIGHT: return "MOVEDOWNRIGHT";
    case MOVEDOWNLEFT: return "MOVEDOWNLEFT";
    default: return "NULLSTATE";
  }
}

//used to print a meaningful player collision state rather than a number
const char* getPlayerCollisionStateString(CollisionState state){
  switch (state)
  {
    case NOTHITTING: return "NOTHITTING";
    case HITTING: return "HITTING";
    default: return "NULLSTATE";
  }
}

