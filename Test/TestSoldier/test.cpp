#include "pch.h"
#include "gtest/gtest.h"
#include "../../Soldiers/Attack/CloneAttack.h"

TEST(CloneAttack, updateGun) {
	CloneAttack* attack = new CloneAttack(CloneWeapon::Weapon::DC_15A_CARBINE);
  EXPECT_EQ(attack->getWeapon(), CloneWeapon::Weapon::DC_15A_CARBINE);
}