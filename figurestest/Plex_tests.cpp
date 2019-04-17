#include <gtest.h>
#include "Plex.h"

TEST(plex, can_create_plex_without_throws_0)
{
  ASSERT_NO_THROW(TPlex plex);
}

TEST(plex, can_create_plex_without_throws_1)
{
  TPoint point1(1, 1), point2(2, 2);
  ASSERT_NO_THROW(TPlex plex(&point1, &point2));
}

TEST(plex, can_create_plex_without_throws_2)
{
  TPoint point1(1, 1), point2(2, 2);
  TPlex pl(&point1, &point2);
  ASSERT_NO_THROW(TPlex plex(pl));
}

TEST(plex, can_create_plex_without_throws_3)
{
  TPoint point1(1, 1), point2(2, 2), point3(2, 3);
  TPlex pl(&point1, &point2);
  ASSERT_NO_THROW(TPlex plex(&pl, &point3));
}

TEST(plex, can_create_plex_without_throws_4)
{
  TPoint point1(1, 1), point2(2, 2), point3(2, 3);
  TPlex pl(&point1, &point2);
  TPlex plex(&pl, &point3);
  ASSERT_NO_THROW(TPlex plexres(pl));
}

TEST(plex, can_add_line_to_plex_without_throws)
{
  TPoint point1(1, 1), point2(2, 2), point3(2, 3);
  TPlex pl(&point1, &point2);
  TPlex plex(&pl, &point3);
  TLine line;
  TPoint point4(3, 3);
  line.SetPoint1(&point4);
  line.SetPoint2(&point3);
  ASSERT_NO_THROW(plex += line);
}

TEST(plex, can_add_line_to_plex_without_throws_1)
{
  TPoint point1(1, 1), point2(2, 2), point3(2, 3);
  TPlex pl(&point1, &point2);
  TPlex plex(&point3, &pl);
  TLine line;
  TPoint point4(3, 3);
  line.SetPoint1(&point4);
  line.SetPoint2(&point3);
  ASSERT_NO_THROW(plex += line);
}

TEST(plex, can_add_line_to_plex_without_throws_2)
{
  TPoint point1(1, 1), point2(2, 2), point3(2, 3);
  TPlex pl(&point1, &point2);
  TPlex plex(&point3, &pl);
  TLine line;
  TPoint point4(3, 3);
  line.SetPoint1(&point1);
  line.SetPoint2(&point4);
  ASSERT_NO_THROW(plex += line);
}

TEST(plex, can__throws_if_add_wrong_line)
{
  TPoint point1(1, 1), point2(2, 2), point3(2, 3);
  TPlex pl(&point1, &point2);
  TPlex plex(&point3, &pl);
  TLine line;
  TPoint point4(3, 3);
  TPoint point5(4, 5);
  line.SetPoint1(&point4);
  line.SetPoint2(&point5);
  ASSERT_ANY_THROW(plex += line);
}