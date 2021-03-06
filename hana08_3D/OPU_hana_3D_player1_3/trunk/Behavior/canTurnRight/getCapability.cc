#include "canturnright.ih"

Behavior::ConfidenceInterval CanTurnRight::getCapability(rf<Behavior::State> s, rf<Behavior::Goal> g)
{
  rf<StateVarNode> angleNode = rf_cast<StateVarNode>(g->findDeep("Angle"));
  if (!angleNode)
  {
    _debugLevel1("CanTurnRight doesn't understand!");
//    std::cout << "CanTurnRiht doesn't understand!" << std::endl;
    return ConfidenceInterval(-1.0, 0.0);
  }
    
  StateVar angleVar = angleNode->getVar();
  double angle = angleVar.second.mean();
  
  _debugLevel4("Angle: " << angle);
//  std::cout << "In CanTurnRight::getCapability()" << std::endl << "  Angle: " << angle << std::endl;
/*
  WorldModel& wm = WorldModel::getInstance();
  Vector3D straight(1.0, 0.0, 0.0);
  double ballDir = straight.angle(wm.getObjectVector(Types::BALL).getMu()) / M_PI * 180.0;
  if(wm.getObjectPosition(Types::BALL).getMu().getY() < 0)
	ballDir *= -1.0;
*/
  if (angle > 5)// || !wm.onMyFeet())
  {
  	_debugLevel3("Can't turn right");
    return ConfidenceInterval(-1.0, 0.0);
  }
  _debugLevel4("Can turn right");
  return ConfidenceInterval(0.5, 0.2);
}
