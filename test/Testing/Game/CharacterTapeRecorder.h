#pragma once

#include <span>
#include <utility>
#include <type_traits>

#include "Engine/Objects/Character.h"

#include "TestController.h"

/**
 * Tape recorder for character properties.
 *
 * Plural methods return a tape of vectors, with one element for each character in party. Singular methods take a
 * 0-based character index and return a tape for this character.
 *
 * For example:
 * - `hp(0)` returns a tape of health points for the 1st character.
 * - `hps()` returns a tape where each element is a vector of four `int`s - health points for the whole party.
 */
class CharacterTapeRecorder {
 public:
    explicit CharacterTapeRecorder(TestController *controller);

    template<class Callback, class T = std::decay_t<std::invoke_result_t<Callback, const Character &>>>
    TestMultiTape<T> custom(Callback callback) {
        return _controller->recordTape([callback = std::move(callback)] {
            AccessibleVector<T> result;
            for (const Character &character : characters())
                result.push_back(callback(character));
            return result;
        });
    }

    template<class Callback, class T = std::decay_t<std::invoke_result_t<Callback, const Character &>>>
    TestTape<T> custom(int characterIndex, Callback callback) {
        return _controller->recordTape([characterIndex, callback = std::move(callback)] {
            return callback(characters()[characterIndex]);
        });
    }

    TestTape<int64_t> experience(int characterIndex);
    TestMultiTape<int64_t> experiences();

    TestTape<PortraitId> portrait(int characterIndex);
    TestMultiTape<PortraitId> portraits();

    TestTape<int> hp(int characterIndex);
    TestMultiTape<int> hps();

    TestTape<int> mp(int characterIndex);
    TestMultiTape<int> mps();

    TestTape<int> ac(int characterIndex);
    TestMultiTape<int> acs();

    TestTape<int> level(int characterIndex);
    TestMultiTape<int> levels();

    TestTape<int> skillLevel(int characterIndex, Skill skill);
    TestMultiTape<int> skillLevels(Skill skill);

    TestTape<bool> hasSkill(int characterIndex, Skill skill);
    TestMultiTape<bool> haveSkills(Skill skill);

    TestTape<Condition> condition(int characterIndex);
    TestMultiTape<Condition> conditions();

    TestTape<int> resistance(int characterIndex, Attribute resistance);
    TestMultiTape<int> resistances(Attribute resistance);

    TestTape<int> stat(int characterIndex, Attribute stat);
    TestMultiTape<int> stats(Attribute stat);

    TestTape<bool> hasBuff(int characterIndex, CharacterBuff buff);
    TestMultiTape<bool> haveBuffs(CharacterBuff buff);

    TestTape<SpellId> quickSpell(int characterIndex);
    TestMultiTape<SpellId> quickSpells();

    TestTape<bool> hasItem(int characterIndex, ItemId itemId);
    TestMultiTape<bool> haveItem(ItemId itemId);

    TestTape<Class> clazz(int characterIndex);
    TestMultiTape<Class> classes();

    TestTape<bool> isRecovering(int characterIndex);
    TestMultiTape<bool> areRecovering();

 private:
    static std::span<Character> characters();

 private:
    TestController *_controller = nullptr;
};
