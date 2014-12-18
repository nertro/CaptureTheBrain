// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/Navigation/NavAreas/NavArea.h"
#include "AI/Navigation/RecastNavMesh.h"

#include "JumpNavArea.generated.h"

/**
 * 
 */

UENUM()
namespace ENavAreaFlag
{
	enum Type
	{
		Jump,
		Fall
	};
}

namespace FNavAreaHelper
{
	FORCEINLINE bool IsSet(uint16 Flags, ENavAreaFlag::Type Bit) { return (Flags & (1 << Bit)) != 0; }
	FORCEINLINE void Set(uint16& Flags, ENavAreaFlag::Type Bit) { Flags |= (1 << Bit); }

	FORCEINLINE bool IsNavLink(const FNavPathPoint& PathVert) { return (FNavMeshNodeFlags(PathVert.Flags).PathFlags & RECAST_STRAIGHTPATH_OFFMESH_CONNECTION) != 0; }
	FORCEINLINE bool HasJumpFlag(const FNavPathPoint& PathVert) { return IsSet(FNavMeshNodeFlags(PathVert.Flags).AreaFlags, ENavAreaFlag::Jump); }
	FORCEINLINE bool HasFallFlag(const FNavPathPoint& PathVert) { return IsSet(FNavMeshNodeFlags(PathVert.Flags).AreaFlags, ENavAreaFlag::Fall); }
}

UCLASS()
class CAPTHEBRAIN_API UJumpNavArea : public UNavArea
{
	GENERATED_UCLASS_BODY()
	
};
