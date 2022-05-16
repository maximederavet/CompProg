/**
 * @fn static cell *create_cell(Polyligne *data)
 * @brief Crée une nouvelle cellule
 *
 * @param data, la polyligne à stocker dans la partie utile de la cellule
 * 
 * @return un pointuer vers la nouvelle cellule créée, elle n'est liéeà rien pour l'instant.
 */
static cell *create_cell(Point2D *data){
    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->prev = NULL;
    n_cell->data = data;
    n_cell->next = NULL;
    
    return n_cell;
}//end create_cell()