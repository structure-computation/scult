nb_dim = Parameter( type_par='unsigned', par_range=[1,2,3], default_value=3 ) #dimension de l'espace a considerer
nvi = Parameter( type_par='unsigned', par_range=[0,1,2,3], default_value=0 ) # nombre de variable d'interpolation 0 = point 1 ligne 2 surface 3 volume


def get_carac(carac):
    """this function is called for each set of parameters and for each kind of element """
    carac.valid = True #nvi<=nb_dim
    carac.dim = nb_dim
    carac.Tpos = 'double'
    #champs globaux
    carac.globaldata=[
        ]
    #champs lies aux noeuds
    carac.nodaldata = [
        DM( name='qtrans', dm_type='Vec<double,%s>'%nb_dim, unit='', default_value='0' ),        
        ]
    carac.nvi_to_subs_range = nb_dim
 
     
def get_elem_choice(nvi_to_subs,skin):

   
    dataonelem = [
       DM( name='type', dm_type='double', unit='', default_value='0' ),
       DM( name='num', dm_type='unsigned', unit='', default_value='0' ),
       DM( name='num_group', dm_type='unsigned', unit='', default_value='0' ),
       DM( name='elem', dm_type='Vec<unsigned>', unit='', default_value='' ),
       DM( name='F', dm_type='Vec<double,%s>'%nb_dim, unit='Mpa', default_value='0' ),
       DM( name='W', dm_type='Vec<double,%s>'%nb_dim, unit='m/s', default_value='0' ), 
       DM( name='dWn', dm_type='Vec<double,%s>'%nb_dim, unit='m/s', default_value='0' ), 
       DM( name='dWt', dm_type='Vec<double,%s>'%nb_dim, unit='m/s', default_value='0' ), 
       DM( name='dissipation', dm_type='Vec<double,%s>'%nb_dim, unit='J', default_value='0' ), 
       DM( name='d', dm_type='double', unit='', default_value='0' ), 
        #DM( name='degr', dm_type='double', unit='', default_value='0' ),
    ]
     
    if nvi-nvi_to_subs==0: return [ ('NodalElement','DefaultBehavior',dataonelem) ]
    if nvi-nvi_to_subs==1: return [ ('Bar','DefaultBehavior',dataonelem),('Bar_3','DefaultBehavior',dataonelem) ]
    if nvi-nvi_to_subs==2: return [ ('Triangle','DefaultBehavior', dataonelem ),('Quad','DefaultBehavior', dataonelem ),('Triangle_6','DefaultBehavior', dataonelem ),('Quad_8','DefaultBehavior', dataonelem )]
    if nvi-nvi_to_subs==3: return [ ('Tetra','DefaultBehavior',dataonelem) ]
    return []
