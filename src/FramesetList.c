//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <XmlElement.h>
#include <XmlDocument.h>
#include "FramesetList.h"
#include "Frameset.h"

/**
 * A constructor of {@link FramesetList} class which reads all frameset files inside the files.txt file. For each
 * filename inside that file, the constructor creates a Frameset and puts in inside the frames {@link ArrayList}.
 */
Frameset_list_ptr create_frameset_list() {
    Frameset_list_ptr frameset_list = malloc(sizeof(Frameset_list));
    frameset_list->frames = create_array_list();
    Xml_element_ptr framesNode, frameSetNode;
    Xml_document_ptr doc = create_xml_document("turkish-propbank.xml");
    parse(doc);
    framesNode = doc->root;
    frameSetNode = framesNode->first_child;
    while (frameSetNode != NULL){
        add_frameset(frameset_list, create_frameset2(frameSetNode));
        frameSetNode = frameSetNode->next_sibling;
    }
    return frameset_list;
}

void free_frameset_list(Frameset_list_ptr frameset_list) {
    free_array_list(frameset_list->frames, (void (*)(void *)) free_frameset);
    free(frameset_list);
}

/**
 * The size_of_predicate method returns the size_of_roleset of the frames {@link ArrayList}.
 *
 * @return the size_of_roleset of the frames {@link ArrayList}.
 */
int size(Frameset_list_ptr frameset_list) {
    return frameset_list->frames->size;
}

/**
 * The getFrameSet method returns the frameset_list at the given index.
 *
 * @param index  Index of the frameset_list
 * @return {@link Frameset} at the given index.
 */
Frameset_ptr get_frameset(Frameset_list_ptr frameset_list, int index) {
    return array_list_get(frameset_list->frames, index);
}

/**
 * The addFrameset method takes a {@link Frameset} as input and adds it to the frames {@link ArrayList}.
 *
 * @param frameset  Frameset to be added
 */
void add_frameset(Frameset_list_ptr frameset_list, Frameset_ptr frameset) {
    array_list_add(frameset_list->frames, frameset);
}

/**
 * getFrameSet method returns the {@link Frameset} with the given synSet id.
 *
 * @param synSetId  Id of the searched {@link Frameset}
 * @return {@link Frameset} which has the given id.
 */
Frameset_ptr get_frameset_with_id(Frameset_list_ptr frameset_list, char *synset_id) {
    for (int i = 0; i < frameset_list->frames->size; i++){
        Frameset_ptr frame = array_list_get(frameset_list->frames, i);
        if (strcmp(frame->id, synset_id) == 0){
            return frame;
        }
    }
    return NULL;
}

/**
 * frameExists method checks if there is a {@link Frameset} with the given synSet id.
 *
 * @param synSetId  Id of the searched {@link Frameset}
 * @return true if the {@link Frameset} with the given id exists, false otherwise.
 */
int frame_exists(Frameset_list_ptr frameset_list, char *synset_id) {
    for (int i = 0; i < frameset_list->frames->size; i++){
        Frameset_ptr frame = array_list_get(frameset_list->frames, i);
        if (strcmp(frame->id, synset_id) == 0){
            return 1;
        }
    }
    return 0;
}
