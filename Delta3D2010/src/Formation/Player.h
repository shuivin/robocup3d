//
// C++ Interface: Player
//
// Description: 
//
//
// Author: delta3d team 2009 <deltateams2009@gmail.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef PLAYER_H
#define PLAYER_H

#include "../Utility/Types.h"
#include "../WorldModel/WorldModel.h"
#include "../Connection/Connection.h"
#include "Formation.h"

class Player
{

private:


public:
    Player();

    ~Player();
    
     /** initalization the player */
    bool init();
    
    bool beam();

    bool beforKickOfBeam();
    
      /** think what need to do, i.e make the decision */
    virtual void think();

protected:

    ///////// interface for TeamPlayer ////////////
    /** the paly-on mode, mainly loop */
    virtual void playPlayOn() = 0;

    /** before kick off */
    virtual void playBeforeKickOff() = 0;

    /** kick off */
    void playKickOff();

    virtual void playOurKickOff() = 0;

    virtual void playOppKickOff() = 0;

    /** kick in */
    void playKickIn();

    virtual void playOurKickIn() = 0;

    virtual void playOppKickIn() = 0;

    /** corner kick */
    void playCornerKick();

    virtual void playOurCornerKick() = 0;

    virtual void playOppCornerKick() = 0;

    /** goal kick */
    void playGoalKick();

    virtual void playOurGoalKick() = 0;

    virtual void playOppGoalKick() = 0;

    /** offside */
    void playOffSide();

    virtual void playOurOffSide() = 0;

    virtual void playOppOffSide() = 0;

    /** game over */
    virtual void playGameOver() = 0;

    /** Gooooooooooooooooal */
    void playGoal();

    virtual void playOurGoal() = 0;

    virtual void playOppGoal() = 0;

    /** free kick */
    void playFreeKick();

    virtual void playOurFreeKick() = 0;
    
    virtual void playOppFreeKick() = 0;
    
    virtual bool mustBeam();
 
    virtual bool mustBeforKickOfBeam();
    
protected:

};

#endif