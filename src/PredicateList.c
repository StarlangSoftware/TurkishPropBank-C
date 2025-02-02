//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <XmlElement.h>
#include <XmlDocument.h>
#include "PredicateList.h"
#include "Predicate.h"
#include "Memory/Memory.h"

/**
 * A constructor of PredicateList class which reads all predicate files inside the 'Frames' folder. For each
 * file inside that folder, the constructor creates a Predicate and puts in inside the list HashMap.
 */
Predicate_list_ptr create_predicate_list() {
    Predicate_list_ptr result = malloc_(sizeof(Predicate_list), "create_predicate_list");
    result->list = create_string_hash_map();
    Xml_element_ptr framesNode, frameSetNode, predicateNode, roleSetNode, rolesNode, roleNode;
    Xml_document_ptr xml_document = create_xml_document("english-propbank.xml");
    parse(xml_document);
    framesNode = xml_document->root;
    frameSetNode = framesNode->first_child;
    while (frameSetNode != NULL) {
        predicateNode = frameSetNode->first_child;
        while (predicateNode != NULL) {
            if (has_attributes(predicateNode)) {
                char *lemma = get_attribute_value(predicateNode, "lemma");
                Predicate_ptr newPredicate = create_predicate(lemma);
                roleSetNode = predicateNode->first_child;
                while (roleSetNode != NULL) {
                    if (has_attributes(roleSetNode)) {
                        char *id = get_attribute_value(roleSetNode, "id");
                        char *name = get_attribute_value(roleSetNode, "name");
                        Roleset_ptr newRoleSet = create_roleset(id, name);
                        rolesNode = roleSetNode->first_child;
                        if (rolesNode != NULL) {
                            roleNode = rolesNode->first_child;
                            while (roleNode != NULL) {
                                if (has_attributes(roleNode)) {
                                    char *description = get_attribute_value(roleNode, "descr");
                                    char *f = get_attribute_value(roleNode, "f");
                                    char *n = get_attribute_value(roleNode, "n");
                                    add_role(newRoleSet, create_role(description, f, n));
                                }
                                roleNode = roleNode->next_sibling;
                            }
                        }
                        add_roleset(newPredicate, newRoleSet);
                    }
                    roleSetNode = roleSetNode->next_sibling;
                }
                hash_map_insert(result->list, newPredicate->lemma, newPredicate);
            }
            predicateNode = predicateNode->next_sibling;
        }
        frameSetNode = frameSetNode->next_sibling;
    }
    free_document(xml_document);
    return result;
}

/**
 * Destructor of PredicateList object. Frees memory allocated for list hash map.
 * @param predicate_list Current predicate list.
 */
void free_predicate_list(Predicate_list_ptr predicate_list) {
    free_hash_map(predicate_list->list, (void (*)(void *)) free_predicate);
    free_(predicate_list);
}

/**
 * The size method returns the number of predicates inside the list.
 *
 * @return the size of the list HashMap.
 */
int size_of_predicate_list(const Predicate_list* predicate_list) {
    return predicate_list->list->count;
}

/**
 * getPredicate method returns the Predicate with the given lemma.
 *
 * @param lemma  Lemma of the searched predicate
 * @return Predicate which has the given lemma.
 */
Predicate_ptr get_predicate(const Predicate_list* predicate_list, const char *lemma) {
    return hash_map_get(predicate_list->list, lemma);
}

/**
 * The method returns all lemma in the predicate list.
 * @return All lemma in the predicate list.
 */
Array_list_ptr get_lemma_list(const Predicate_list* predicate_list) {
    return key_list(predicate_list->list);
}
