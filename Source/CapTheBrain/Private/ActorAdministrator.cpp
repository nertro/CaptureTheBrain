// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ActorAdministrator.h"

ActorAdministrator* ActorAdministrator::instance = 0;

ActorAdministrator::ActorAdministrator()
{
	brainBase = nullptr;
}

ActorAdministrator::~ActorAdministrator()
{
	delete brainBase;
	delete arrow;
	delete brain;
}


