#include <stdlib.h>
#include <string.h>
#include "hashmap_string.h"

// ========================================================================
// 1. 비공개(Private) 구조체 및 함수 정의
// ========================================================================

// 이 구조체와 함수들은 이 파일 안에서만 사용되며, 외부에는 노출되지 않는다

// 키-값 쌍과 다음 노드를 가리키는 포인터를 담는 해시 맵 엔트리
typedef struct Ht_Entry {
    char* key;
    char* value;
    struct Ht_Entry* next;
} Ht_Entry;

// 실제 HashMap 구조체의 전체 정의는 여기에 위치한다
// 해시 맵 전체를 나타내는 구조체
struct StringHashMap {
    Ht_Entry** buckets;
    size_t capacity;
    size_t count;
};

// djb2 해시 함수: 문자열 키를 받아 해시 값을 생성
static unsigned long hash_function(const char* key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        // hash = hash * 33 + c
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

// ========================================================================
// 2. 공개(Public) 함수 구현
// ========================================================================

// 헤더 파일에 선언된 함수들의 실제 코드를 작성한다

/**
 * @brief 새로운 해시 맵 생성한다
 * @param capacity 초기 버킷 용량
 * @return 성공 시 생성된 해시 맵 포인터, 실패 시 NULL
 */
StringHashMap* shm_create(size_t capacity) {
    // 1. 해시 맵 구조체 자체에 대한 메모리 할당
    StringHashMap* map = (StringHashMap*)malloc(sizeof(StringHashMap));

    if (map == NULL) {
        return NULL;
    }

    map->capacity = capacity;
    map->count = 0;

    // 2. 버킷 배열에 대한 메모리 할당 (엔트리 포인터를 저장할 공간)
    // calloc을 사용하면 모든 포인터가 NULL로 자동 초기화됨
    map->buckets = (Ht_Entry**)calloc(map->capacity, sizeof(Ht_Entry*));
    if (map->buckets == NULL) {
        free(map); // 실패 시 이미 할당된 메모리 해제
        return NULL;
    }

    return map;
}

/**
 * @brief 해시 맵과 관련된 모든 메모리를 해제한다
 * @param map 해제할 해시 맵
 */
void shm_destroy(StringHashMap* map) {
    // 입력 유효성 검사
    if (map == NULL) {
        return;
    }

    for (size_t i = 0; i < map->capacity; i++) {
        Ht_Entry* entry = map->buckets[i];
        // 각 버킷의 연결 리스트를 순회하며 모든 노드 해제
        while (entry != NULL) {
            Ht_Entry* next_entry = entry->next;
            // 엔트리 내부에 동적 할당된 키와 값 해제
            free(entry->key);
            free(entry->value);
            free(entry);
            entry = next_entry;
        }
    }

    // 버킷 배열과 맵 구조체 자체를 해제
    free(map->buckets);
    free(map);
}

/**
 * @brief 해시 맵에 키-값 쌍을 삽입하거나 갱신한다
 * @param map 대상 해시 맵
 * @param key 문자열 키
 * @param value 문자열 값
 */
void shm_set(StringHashMap* map, const char* key, const char* value) {
    // 1. 입력 유효성 검사
    if (map == NULL || key == NULL || value == NULL) {
        return;
    }

    // 2. 키를 해싱하여 버킷 인덱스 계산
    unsigned long hash = hash_function(key);
    size_t index = hash % map->capacity;

    // 3. 해당 버킷의 연결 리스트를 순회하며 키가 이미 존재하는지 확인
    Ht_Entry* entry = map->buckets[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            // 키가 존재하면 -> 값(value)만 갱신
            free(entry->value); // 이전 값을 메모리에서 해제
            entry->value = strdup(value); // 새 값의 복사본을 할당하여 저장
            return; // 작업 완료
        }
        entry = entry->next;
    }

    // 4. 키가 존재하지 않으면 -> 사로운 엔트리를 생성하여 연결 리스트의 맨 앞에 추가
    Ht_Entry* new_entry = (Ht_Entry*)malloc(sizeof(Ht_Entry));
    if (new_entry == NULL) {
        return; // 메모리 할당 실패
    }

    // strdup: 문자열을 복제하고 새 메모리를 할당해주는 편리한 함수
    // 참고: `strdup()` 함수는 내부적으로 `malloc()`을 호출하므로, `free()`로 해제해주어야 한다
    // `ht_destroy`와 `ht_set`의 값 갱신 부분에서 이를 처리하고 있다
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);

    // 새 엔트리를 기존 연결 리스트의 헤드로 만듦
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
    map->count++;
}

/**
 * @brief 키를 사용하여 해시 맵에서 값을 검색한다
 * @param map 대상 해시 맵
 * @param key 검색할 문자열 키
 * @return 키에 해당하는 값을 반환, 키가 존재하지 않으면 NULL을 반환
 */
char* shm_get(StringHashMap* map, const char* key) {
    // 1. 입력 유효성 검사
    if (map == NULL || key == NULL) {
        return NULL;
    }

    // 2. 키를 해싱하여 버킷 인덱스 계산
    unsigned long hash = hash_function(key);
    size_t index = hash % map->capacity;

    // 3. 해당 버킷의 연결 리스트를 순회
    Ht_Entry* entry = map->buckets[index];
    while (entry != NULL) {
        // 4. 키가 일치하는 엔트리를 찾으면 값을 반환
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }

    // 키를 찾지 못하면 NULL 반환
    return NULL;
}

/**
 * @brief 해시 맵에서 키-값 쌍을 삭제한다
 * @param map 대상 해시 맵
 * @param key 삭제할 문자열 키, 키가 존재하지 않으면 아무 작업도 하지 않는다
 */
void shm_delete(StringHashMap* map, const char* key) {
    // 1. 입력 유효성 검사
    if (map == NULL || key == NULL) {
        return;
    }

    // 2. 키를 해싱하여 버킷 인덱스 계산
    unsigned long hash = hash_function(key);
    size_t index = hash % map->capacity;

    // 3. 두 개의 포인터를 사용하여 해당 버킷의 연결 리스트를 순회
    //    'entry'는 현재 노드를, 'prev'는 이전 노드를 가리킴
    Ht_Entry* entry = map->buckets[index];
    Ht_Entry* prev = NULL;

    while (entry != NULL) {
        // 4. 키가 일치하는 노드를 찾음
        if (strcmp(entry->key, key) == 0) {
            // 5. 노드를 연결 리스트에서 제거
            if (prev == NULL) {
                // Case 1: 삭제할 노드가 연력 리스트의 첫 번째 노드(헤드)인 경우
                // 버킷의 시작 포인터를 다음 노드로 변경
                map->buckets[index] = entry->next;
            } else {
                // Case 2: 삭제할 노드가 중간 또는 마지막 노드인 경우
                // 이전 노드의 "next" 포인터가 현재 노드의 다음 노드를 가리키도록 변경
                prev->next = entry->next;
            }

            // 6. 삭제된 노드의 메모리를 안전하게 해제
            free(entry->key);
            free(entry->value);
            free(entry);
            
            // 7. 맵의 총 항목 수를 감소
            map->count--;

            // 삭제가 완료되었으므로 함수 종료
            return;
        }

        // 키가 일치하지 않으면, 다음 노드로 이동
        prev = entry;
        entry = entry->next;
    }
    
    // 루프가 끝날 때까지 키를 찾지 못하면 아무 작업도 하지 않고 종료
}