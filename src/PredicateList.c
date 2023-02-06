//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <XmlElement.h>
#include <XmlDocument.h>
#include "PredicateList.h"
#include "Predicate.h"

/**
 * A constructor of {@link PredicateList} class which reads all predicate files inside the 'Frames' folder. For each
 * file inside that folder, the constructor creates a Predicate and puts in inside the list {@link HashMap}.
 */
Predicate_list_ptr create_predicate_list() {
    Predicate_list_ptr result = malloc(sizeof(Predicate_list));
    result->list = create_hash_map((unsigned int (*)(void *, int)) hash_function_string,
                                   (int (*)(void *, void *)) compare_string);
    Xml_element_ptr framesNode, frameSetNode, predicateNode, roleSetNode, rolesNode, roleNode;
    Xml_document_ptr xmlDocument = create_xml_document("english-propbank.xml");
    parse(xmlDocument);
    framesNode = xmlDocument->root;
    frameSetNode = framesNode->first_child;
    while (frameSetNode != NULL){
        predicateNode = frameSetNode->first_child;
        while (predicateNode != NULL){
            if (has_attributes(predicateNode)){
                char* lemma = get_attribute_value(predicateNode, "lemma");
                Predicate_ptr newPredicate = create_predicate(lemma);
                roleSetNode = predicateNode->first_child;
                while (roleSetNode != NULL){
                    if (has_attributes(roleSetNode)){
                        char* id = get_attribute_value(roleSetNode, "id");
                        char* name = get_attribute_value(roleSetNode, "name");
                        Roleset_ptr newRoleSet = create_roleset(id, name);
                        rolesNode = roleSetNode->first_child;
                        if (rolesNode != NULL){
                            roleNode = rolesNode->first_child;
                            while (roleNode != NULL){
                                if (has_attributes(roleNode)){
                                    char* description = get_attribute_value(roleNode, "descr");
                                    char* f = get_attribute_value(roleNode, "f");
                                    char* n = get_attribute_value(roleNode, "n");
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
    return result;
}

void free_predicate_list(Predicate_list_ptr predicate_list) {
    free_hash_map(predicate_list->list, (void (*)(void *)) free_predicate);
    free(predicate_list);
}

/**
 * The size method returns the number of predicates inside the list.
 *
 * @return the size of the list {@link HashMap}.
 */
int size_of_predicate_list(Predicate_list_ptr predicate_list) {
    return predicate_list->list->count;
}

/**
 * getPredicate method returns the {@link Predicate} with the given lemma.
 *
 * @param lemma  Lemma of the searched predicate
 * @return {@link Predicate} which has the given lemma.
 */
Predicate_ptr get_predicate(Predicate_list_ptr predicate_list, char *lemma) {
    return hash_map_get(predicate_list->list, lemma);
}

/**
 * The method returns all lemma in the predicate list.
 * @return All lemma in the predicate list.
 */
Array_list_ptr get_lemma_list(Predicate_list_ptr predicate_list) {
    return key_list(predicate_list->list);
}
