#include "wait.ih"

rf<Behavior::Goal> Wait::generateGoal(unsigned step, unsigned slot)
{
  rf<Goal> goal = new Goal();
  rf<OrNode> dis = goal->addDisjunct();
  rf<AndNode> con = dis->addConjunct();
  
  // con->addVar("Var", 0, 1);
  con->addVar("Weight1", 0.1, 0.1);
  
  return goal;
}
