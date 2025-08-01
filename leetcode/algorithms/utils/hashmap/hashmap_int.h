#ifndef HASHMAP_INT_H // Include Guard: 중복 포함을 방지
#define HASHMAP_INT_H

#include <stddef.h> // size_t 타입을 위해 필요

/**
 * ========================================================================
 * 1. 공개(Public) 구조체 선언 (Opaque Pointer 기법)
 * ========================================================================
 */

// 사용자는 HashMap이 어떻게 생겼는지 알 필요가 업다
// 포인터로만 다루게 하여 내부 구현을 숨긴다 (캠슐화)
typedef struct IntHashMap IntHashMap;


/**
 * ========================================================================
 * 2. 공개(Public) 함수 원형 선언
 * ========================================================================
 */

// 이 함수들이 이 라이브러리의 "API(Application Programming Interface)"가 된다

/**
 * @brief 새로운 해시 맵을 생성한다
 * @param capacity 초기 버킷 용량
 * @param init_value 키 없을 시 반환 값
 * @return 성공 시 생성된 해시 맵 포인터, 실패 시 NULL
 */
IntHashMap* ihm_create(size_t capacity, int init_value);

/**
 * @brief 해시 맵과 관련된 모든 메모리를 해제한다
 * @param map 해제할 해시 맵
 */
void ihm_destroy(IntHashMap* map);

/**
 * @brief 해시 맵에 키-값 쌍을 삽입하거나 갱신한다
 * @param map 대상 해시 맵
 * @param key 숫자 키
 * @param value 숫자 값
 */
void ihm_set(IntHashMap* map, const int key, const int value);

/**
 * @brief 키를 사용하여 해시 맵에서 값을 검색한다
 * @param map 대상 해시 맵
 * @param key 검색할 숫자 키
 * @return 키에 해당하는 값을 반환, 키가 존재하지 않으면 map->init_value 반환
 */
int ihm_get(IntHashMap* map, const int key);

/**
 * @brief 해시 맵에서 키-값 쌍을 삭제한다.
 * @param map 대상 해시 맵.
 * @param key 삭제할 숫자 키, 키가 존재하지 않으면 아무 작업도 하지 않는다
 */
void ihm_delete(IntHashMap* map, const int key);

#endif