// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"



#define LOG(msg, ...) UE_LOG(InitLog, Log, TEXT(msg), ##__VA_ARGS__)
#define WARN(msg, ...) UE_LOG(InitLog, Warning, TEXT(msg), ##__VA_ARGS__)
#define ERROR(msg, ...) UE_LOG(InitLog, Error, TEXT(msg), ##__VA_ARGS__)